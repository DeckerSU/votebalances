#include <iostream>
#include <cstdint>
#include <map>
#include "curlite/curlite.hpp"
#include "utilstrencodings.h"
#include "tinyformat.h"
#include <cstring>
#include <sstream>
#include "rapidjson/document.h"

using namespace rapidjson;

static const std::map<std::string, std::string> mapAR = 
{
        { "decker", "RHeRFNk2jih5oFedJpgFXx8wPANv5iiFg7" },
        { "alien", "RKa337W7C7K8si4KzUrKYaCRoTw3yVLUJB" },
        { "byozgunn", "RFCissukbVUfsizjwPXVUqxHaH5fKx11Zp" },
        { "chmex", "RYcS41es6jQtd9Pnv1bpMZmLmFAaMojjbX" },
        { "ocean", "R9Jny2pGVYVLjfxsiYCYtf7C6fgd3zxNH6" },
        { "daria", "RFxBgg7HLFxZwb94iyLthKmuK4EZcrFZZy" },
        { "dudezmobi", "RA7VoAW811sZS6CPaM3CwS4VyNyLzmNcKy" },
        { "fediakash", "RJvm1a6SoGfjS6WDobLTPJEjHrAFHv7md1" },
        { "kolo", "RKCXF7EYaAJHmiyDKmubhQ88dYc7CbTZxx" },
        { "nutellalicka", "RRXLDNAmvSC848d6VqRGmNEugrsHx7mfS9" },
        { "pangz", "RHtRNLjyW8jvKQuMa4vHsNgzaE7kpynJRX" },
//      { "paro", "RScDpTu2m23qrufjpK5nh2M6M3x2L8pLuo" },
        { "titomane", "RGKeqvDvbLrGTyEYpEZMJFNK1dW2GnxmnB" },
        { "tonyl", "RNWUrfBmdRmKogYq8ss73UCrP3ipmT54A8" },
//      { "strob", "RStrobARDwHKBDntCa2Ko6oi91n4YMpgSB" },
        { "mcrypt", "RLYYNmQcmC3vGYtGhyCt6HUXQL2kn7vQAa" },
        { "mrlynch", "RC2pD9ietgA27QMhgv8nn5pFo2v7HfmesF" },
        { "dathbezumniy", "RX2wKLEk6M9qp4tWPft2un9ysnFURA2a3y" },
        { "goldenman", "RL9srwE4yafTRammxmGhzG8tVp6VkbKGg8" },
        { "starfleet", "RLQ3GrJstg3pgmvEU6hjfyYqbHuyqgTnWM" },
        { "cipi", "RE1NaK7Bp5Xy127nbFLmu4QVxPPnQkoe4h" },
        { "metaphilibert", "RMetaARvKiEj16LNdqG8QmxzankfCb9p2w" },
};

static const std::map<std::string, std::string> mapEU = 
{
        { "decker", "RAE43rkzYV3YQ5QcR3twTtNxEkQb8RNrBf" },
        { "alien", "REUke3f6vVQiy6FjStpfRt4HUR9jmGxqED" },
//      { "chmex", "RBJGGzKhP7YWoPBoi5AKPm2VJEGy4oodQy" },
        { "dappvader", "RV6TYQ94Sfv1jcapxDJ11n23nNouutn7wn" },
        { "donromero", "RA4TWrEt4YM5trAvhKh79SS8xEcoKHC9SZ" },
        { "fairbanksy", "RDaM2MQsXcwjWBaPCyWgSosMSQ6A5kBGx2" },
        { "jorian", "RPjMFCn13aBbUoWzyUCzJFvJZXjqxVqNc4" },
        { "mihailo", "RFwX8TWTgFwgKEW4DFBWG6Lpfw1nC4La9Z" },
        { "mx222", "RAGTPcaNh3DRmsckA1ugSJZdo64jXGn8jo" },
        { "slyris", "RXQYUDdVM2tf4bSE8Z2Duw6sfF8JDyVcKx" },
        { "smdmitry", "RSMDmitryCzhPJkKCZVAJi2XyudqP4Tfzq" },
        { "titomane", "RSxsxyT5fqX3D3LzexGdUTNvs6zyKbyBD9" },
        { "block9", "RSmMfwnBZJtjqBjnEYF2dyCquXJvk1bK2Q" },
//      { "strob", "RStrobEUa7sHUamRfaWyX8DN2bpKiq9YPZ" },
        { "madmax", "RLTvCWLwQyyoeoouVjdg7gvEAYNvSyypmC" },
        { "hastrup", "RR5ML3KMuvMZXkNDeB32DLWvVkkpQyuT32" },
        { "yurii-khi", "RFKQRyp2Rst9BdozzoqKnsRcUtiWN8cQny" },
        { "pirate", "RHs4FTLEYn7CcbLdRBNDbm6iNTUwxpj8ML" },
        { "ca333", "RFh6JRqPpnoxboXWufWWUFvpZ67DmMmcrz" },
        { "cipi", "RTMSZ28BvFvy9eGE8FTSstX1APXMXimXdN" },
        { "van", "RJ3V9y7uErFNvDygbyu2VnNSimvTuHKouM" },
        { "node-9", "RCQNDzwPtPyrnNR4ENgZQneDXST1GM4oKt" },
        { "syl", "RNrdKjuMdQzYpcz7CLTDH6gXwGGQkhXj26" },
        { "arnomad", "RArnomd78pGmGXKuMVZzZ5hxcRzZHBimf6" },
};

static const std::map<std::string, std::string> mapNA = 
{
        { "alien", "RESSSyiJy3Xzek15k9sxB87cCdjPwAuAXL" },
        { "chmex", "RAeX5HQCa6rhYZsm6PKX4ZTQ9MiMHffavJ" },
        { "computergenie", "RVoteCGxquRNeHWGiHC6vxzpXBodKt3P88" },
        { "crackers", "R9WxJtF2JjVZriaN2FRf6592HUFZSuqvnn" },
        { "dragonhound", "RKpigLeT5rgXy31yubpgWcJ91i1TZbZg5h" },
        { "greer", "RGJ6jfW5qs2e9jQUHFJ2rePpwTWV2YyJvh" },
        { "kulim", "RLEeYUDycBbmKvN1irX5jZohskrynntFcH" },
        { "nodeone", "RNjeQcneBWgkPFk1stynJWN9gnNLpgBzud" },
        { "ptyx", "RHZAnQxv6tGajPppWywpkP5W8JXQR3QEvi" },
        { "rustytwilight", "RUpsdjVayPNBBwAJS3idFbXxUKZTLS185u" },
        { "theerbeen", "RXbwWvgd3RoMVmxwvHqBMDPTt33CxN6nzP" },
        { "strob", "RStrobNmEspEAgB8Jtt6ncK8tCWcGm77na" },
        { "madmax", "RUkXigRwEwc18wvzP6UXBgL3dPhAYMVK1j" },
        { "webworker01", "RLqnbAwfucQEcSzcBXEXAavLTtL1FrWxqJ" },
        { "captainsparrow", "RYAtnKEpD6YgyXq2ssKRFjM2dfv3GnamUM" },
        { "pirate", "RTQZhmZn1YaBBGpKBxDy9aaHTipFCDCTUJ" },
        { "daemonfox", "RDAEmonF9avm7xau2pYWf3UamgHNXrkzpt" },
        { "cipi", "RGayMoe7ptHwmAfVcDsZPnrxM4EsW1REMy" },
        { "mojojojo400", "RHkNZ2G8TwKRd5wmUXryKfykfeSWhVuRNY" },
        { "node-9", "RLvYMe7oB5zsWks4y4ue97xGYjEbfERdT6" },
        { "who-biz", "REyFgygqWpDtYjKhz214CkA6hrA27d6cxX" },
};

static const std::map<std::string, std::string> mapSH = 
{
        { "chmex", "RUFm7G6fnUdZ6sT3qkNYo62SPfgmK7xs6Y" },
        { "darkolisio", "RCVce12PdtCy1L3jiC8y7PYtGCK9crR69U" },
        { "foxminner", "RB9KccHNa7TGAW5Tw9USF7Y84H3cCba2zu" },
        { "gcharang", "RTWgfK47pbhyHWcqEMQUyEK6dtf7VpBYYB" },
        { "nutellalicka", "RUjxoAzgnSrsiiup2ucmfJRrXxTHzNnhFE" },
        { "pbca26", "RSTe7FGtdqTksYLKt3iBfSkrGFZkcGW3x6" },
        { "phm87", "RFmvveVYVRPo8v85J5u3Yd3PgrzSrHZP4S" },
        { "shin-ra77", "R9hH4fEW9Xy8kxSQF7GQQKJ3SDy1Qy3auQ" },
        { "titomane", "REjTMBjhhdnWkiMfBAjuBZUpBvTH4wwcwt" },
        { "workax", "RPvzKxby2fU5zm4q5ySrNdh3NbjgeMcw47" },
        { "zatjum", "RJUM5a3vnajE9fZ5piDGcxvDyryUAHxhKj" },
        { "zatjum_2", "RGrUUMUTJmRU63xUH8sTHQ8qAkwyiyZATR" }, // x2
        { "strob", "RStrobSH68ke1eFmxNehVuJczTEpFX3C4f" },
        { "sheeba", "RR7CECKj4aT7BC7Exq6a5AteVoPRyHEFyx" },
        { "d4v", "RYK2RgXbdHhTyaYmLAAfhYbYwvMmgaG22h" },
        { "mylo", "RARdqVRm3RWvii2kCWZBSteqqZQs7PsVj9" },
        { "kmdude", "RQX3U59fE2kS4KBZxCWhPaEhPbpTfdM2ef" },
        { "hyperstaking", "RQguCHyooUyrPpkWHHQ7S3enU12aLpaeN5" },
        { "drkush", "RNeTapDAtWtgKyeBoBMmaD3Zw3HGvx9ze7" },
        { "metaphilibert", "RMetaSHqEPvuAC1K1TWFx5WwNcMiqPFm8e" },
};

/* Daemon Params */
const std::string rpcuser = "user2221517864";
const std::string rpcpassword = "pass428e1eb1b70448774f7e04a4d39c8624caa769a5256a4e00d3323b040f440ddacb";
const uint16_t rpcport=55638;

const bool fHTML = true;

typedef int64_t CAmount;
static const CAmount COIN = 100000000;
static const CAmount CENT = 1000000;

static const CAmount MAX_MONEY = 21000000 * COIN;

inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

int64_t AmountFromValue(const rapidjson::Value &value)
{
    if (!value.IsString()) throw std::runtime_error("Amount is not string");
    CAmount amount;
    if (!ParseFixedPoint(value.GetString(), 8, &amount)) throw std::runtime_error("Invalid amount");
    if (!MoneyRange(amount)) throw std::runtime_error("Amount out of range");
    return amount;
}

std::string ValueFromAmount(const CAmount& amount)
{
    bool sign = amount < 0;
    int64_t n_abs = (sign ? -amount : amount);
    int64_t quotient = n_abs / COIN;
    int64_t remainder = n_abs % COIN;
    return strprintf("%s%d.%08d", sign ? "-" : "", quotient, remainder);
}

uint64_t getbalance(const std::string &address) {
    uint64_t balance = 0;

    try
    {
        curlite::Easy easy;
        easy.set( CURLOPT_URL, strprintf("http://127.0.0.1:%u", rpcport ));
        //easy.set( CURLOPT_PORT, rpcport);
        easy.set( CURLOPT_USERPWD, strprintf("%s:%s", rpcuser, rpcpassword));
        easy.set( CURLOPT_POST, 1L);
        easy.set( CURLOPT_FOLLOWLOCATION, true );
        //easy.set( CURLOPT_VERBOSE, 1L);

        curlite::List headers;
        headers << "Transfer-Encoding: chunked";
        headers << "Content-Type: application/json";
        easy.set( CURLOPT_HTTPHEADER, headers.get() );

        std::string post_data = strprintf("{\"jsonrpc\":\"1.0\",\"method\":\"getaddressbalance\",\"params\":[\"%s\"]}", address);
        //std::cerr << post_data << std::endl;
        //easy.set( CURLOPT_POSTFIELDSIZE, std::strlen(post_data.c_str()));
        easy.set( CURLOPT_POSTFIELDS, post_data.c_str());
        
        // std::cout << easy << std::endl;
        std::stringstream stream;
        stream << easy;
        std::string strJSON =  stream.str();
        // std::cout << strJSON << std::endl;

        // https://github.com/Tencent/rapidjson/blob/master/example/tutorial/tutorial.cpp
        // https://github.com/Tencent/rapidjson/blob/master/example/messagereader/messagereader.cpp
        // https://github.com/Tencent/rapidjson/blob/master/example/serialize/serialize.cpp

        Document jDocument;
        if (jDocument.ParseInsitu((char *)strJSON.c_str()).HasParseError())
            return balance;

        if (jDocument.IsObject()) {
            if (jDocument["error"].IsNull()) {
                const Value& jRes = jDocument["result"];
                if (jRes["balance"].IsUint64())
                    balance = jRes["balance"].GetUint64();
            }
        }
        

        // double totalSecs = easy.getInfo<double>( CURLINFO_TOTAL_TIME );
        // std::cout << "Request time: " << totalSecs << " s" << std::endl;
    }
    catch( std::exception &e ) {
        std::cerr << "Got an exception: " << e.what() << std::endl;
    }


    return balance;
}

void print_region(const std::string &region, const std::map<std::string, std::string>& mapregion)
{
    if (!fHTML) {
        std::cout <<  region <<std::endl;
        std::cout << std::endl;
    } else {
        std::cout << strprintf("<h3>%s</h3>", region) << std::endl;
        std::cout << "<table class=\"table\">" << std::endl;
        std::cout << "    <thead class=\"thead-dark\">\n\
        <tr>\n\
            <th scope=\"col\">#</th>\n\
            <th scope=\"col\">Node</th>\n\
            <th scope=\"col\" class=\"d-none d-lg-table-cell\">Address</th>\n\
            <th scope=\"col\">Balance</th>\n\
        </tr>\n\
    </thead>\n\
    <tbody>" << std::endl;
    }

    std::map<std::string, CAmount> balances;
    std::vector<std::pair<std::string, CAmount> > vbalances;
    balances.clear(); vbalances.clear();
    for (auto entry : mapregion) balances[entry.first] = getbalance(mapregion.at(entry.first));
    for (const auto entry : balances) vbalances.push_back(entry);
    std::sort(vbalances.begin(), vbalances.end(), [](std::pair<std::string, CAmount> a, std::pair<std::string, CAmount> b) {
        return a.second > b.second;
    });

    uint32_t count = 0;
    for (const auto entry : vbalances) {
        std::string address = mapregion.at(entry.first);
        if (!fHTML) {
            std::cout << strprintf("%lu.\t%20s\t%-34s\t%20s VOTE2021", ++count, entry.first, address, ValueFromAmount(entry.second)) << std::endl;
        } else {
                std::cout << strprintf("        <tr>\n\
            <th scope=\"row\">%lu</th>\n\
            <td><a href=\"https://github.com/KomodoPlatform/NotaryNodes/blob/master/season5/candidates/%s/README.md\" target=\"_blank\">%s</a></td>\n\
            <td class=\"d-none d-lg-table-cell\"><a href=\"https://vote.kmdexplorer.io/address/%s\" target=\"_blank\">%s</a></td>\n\
            <td>%s</td>\n\
        </tr>", ++count, entry.first, entry.first, address, address, ValueFromAmount(entry.second)) << std::endl;
        }
    }

    if (!fHTML) {
        std::cout << std::endl;
    } else {
        std::cout << "    </tbody>\n\
</table>" << std::endl;
    }
}

int main() 
{
    std::cerr << "Let's build stats ..." << std::endl;
    
    // for (auto entry : mapAR)
    //     std::cout << entry.first << " :: " << entry.second << std::endl;
    // std::cout << std::endl;
    
    if (fHTML) {
        std::cout << "<!doctype html>\n\
<html lang=\"en\">\n\
<head>\n\
<meta charset=\"utf-8\">\n\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n\
<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css\" integrity=\"sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO\" crossorigin=\"anonymous\">\n\
</head>\n\
<body>" << std::endl;
        std::cout << "<div class=\"container-sm p-4\">" << std::endl;
        std::cout << "<div class=\"row\">" << std::endl;
        //std::cout << "<h2>VOTE2021 Results</h2>" << std::endl;
        std::cout << "<div class=\"col-sm-6\">" << std::endl;
    }

    print_region("AR", mapAR);
    print_region("EU", mapEU);

    if (fHTML) {
        std::cout << "</div><!-- col-sm -->\n\
        <div class=\"col-sm-6\">" << std::endl;
    }

    print_region("NA", mapNA);
    print_region("SH", mapSH);

    if (fHTML) {
        std::cout << "</div><!-- col-sm -->\n\
</div><!-- row -->\n\
</div><!-- container -->\n\
<!-- Optional JavaScript -->\n\
<script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\" integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\" crossorigin=\"anonymous\"></script>\n\
<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js\" integrity=\"sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49\" crossorigin=\"anonymous\"></script>\n\
<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js\" integrity=\"sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy\" crossorigin=\"anonymous\"></script>\n\
</body></html>" << std::endl;
    }

    return 0;
}
