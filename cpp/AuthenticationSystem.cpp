#include "../hpp/AuthenticationSystem.hpp"

std::string AuthenticationSystem::domain = "http://microssoft.c0.pl/";
std::string AuthenticationSystem::page = "/strona.php";

AuthenticationSystem::AuthenticationSystem()
{
    authToken.login = "";
}

bool AuthenticationSystem::authenticate(std::string login, std::string password) {

    std::cout << login << "||" << password << std::endl;

	sf::Http::Request request(domain, sf::Http::Request::Post);

    request.setMethod(sf::Http::Request::Post);
    request.setUri(page);
    std::ostringstream stream;
    stream << "login=" << login << "&password=" << password;
    request.setBody(stream.str());
    request.setField("Content-Type","application/x-www-form-urlencoded");

    sf::Http http(domain);


    sf::Http::Response response = http.sendRequest(request);
    if (response.getStatus() == sf::Http::Response::Ok)
    {
        std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
        std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
        std::cout << "body: " << response.getBody() << std::endl;
        std::string s = response.getBody();
        std::vector<std::string> vect;
        std::string delimiter = " ";
        std::replace( s.begin(), s.end(), '-', ' ');
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            vect.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        vect.push_back(s);

        if(vect.size()<11) return false;

        authToken.pd.setName(vect[0]);
        authToken.pd.setSecondName(vect[1]);
        authToken.pd.setLastName(vect[2]);
        authToken.pd.setDateOfBirth(Date(std::stoi(vect[3]),std::stoi(vect[4]),std::stoi(vect[5])));
        authToken.pd.setCitizenship(vect[6]);
        authToken.pd.setPESEL(vect[7]);
        authToken.pd.setPhoneNr(vect[8]);
        authToken.pd.setEmail(vect[9]);
        authToken.pd.setAddress(vect[10]);
        authToken.login = vect[11];
    }
    else
    {
        std::cout << "request failed" << std::endl;
    }


    return true;
}

AuthToken AuthenticationSystem::getAuth()
{
    return authToken;
}
