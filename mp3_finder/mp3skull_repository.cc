#include "common.h"
#include "mp3skull_repository.h"
#include "http_connection.h"
#include "default_parser.h"

bool MP3SkullRepository::download(std::string url, std::string destiny_path) {
    return true;
}

std::string MP3SkullRepository::convert_to_restfull_style(std::string search_terms) {
    
    std::string search_terms_converted = boost::replace_all_copy(search_terms, " ", "_");
    
    boost::replace_all(search_terms_converted, "(", "_");
    boost::replace_all(search_terms_converted, ")", "_");
    boost::replace_all(search_terms_converted, "-", "_");
    boost::replace_all(search_terms_converted, "___", "_");
    boost::replace_all(search_terms_converted, "__", "_");
    boost::replace_all(search_terms_converted, "_ ", "_");
    boost::replace_all(search_terms_converted, " _ ", "_");
    boost::replace_all(search_terms_converted, "  _", "_");
    
    boost::algorithm::to_lower(search_terms_converted);
    
    return search_terms_converted;
}

std::string MP3SkullRepository::search(std::string name) {
    std::string page = "/mp3/" + convert_to_restfull_style(name) + ".html";
    std::string content = http_connection_->read("mp3skull.com", page);
    
    
    std::vector<std::string> urls = parser_->parse_lines(content, achar padrao ideal);
    std::cout << "URL: " << urls[0];
    return "";
}

TEST(MP3SkullRepository, ConvertToRestfullStyle) {
    boost::shared_ptr<IHttpConnection> http_connection;
    http_connection.reset(new HttpConnection());

    boost::shared_ptr<IParser> parser;
    parser.reset(new DefaultParser());
    
    MP3SkullRepository repository(http_connection, parser);
    std::string ret = repository.convert_to_restfull_style("Avicii - Wake Me Up (Radio Edit) ");
    EXPECT_EQ("avicii_wake_me_up_radio_edit_", ret);
}


TEST(MP3SkullRepository, SearchMP3) {
    boost::shared_ptr<IHttpConnection> http_connection;
    http_connection.reset(new HttpConnection());

    boost::shared_ptr<IParser> parser;
    parser.reset(new DefaultParser());

    boost::shared_ptr<IRepository> repository;
    repository.reset(new MP3SkullRepository(http_connection, parser));
    
    std::string ret = repository->search("Avicii - Wake Me Up (Radio Edit) ");
    //EXPECT_EQ(true, ret);
}

