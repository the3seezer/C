/*
    theBitRiddler
    3/6/2024
    9:41 PM
    SMS Language
*/
#include <stdio.h>

#define SIZE 160
#define LONG 320

void sToL( char * ); // short to long converter
void lToS( char * ); // long to short converter
void (* method[2] )( char * ) = { sToL, lToS }; // The pointer to our functions

int main(void) {
    const char * SMSWords[189] = {
        "&", "=", ">", "<", "#", "x", "/", "@",
        "404", "401k",
        "Acct", "Ad", "AFAIK", "Approx", "APR", "ASAP", 
        "b/c", "B2B", "B4", "B4N", 
        "BA", "BBL", "BBS", "bkgd",
        "BRB", "BS", "BTW", "btwn", 
        "C&B", "C&S",
        "CEO", "CC", "cf", "CFO", "Co.", "COO", "COOP", "Corp.",
        "cp",
        "CRM", "CSR", "ct", "CTO",
        "CU", "CUL8R", "CYT", 
        "Dept.", "DIV", 
        "e.g.", "EST", "ESP",
        "EOD", "ea", "Ea.", "EOM", "EOT", "EOY", "ERP",
        "f", "FAQ", "F2F", 
        "FWD", "FWIW", "FYI", 
        "G2G", "GDP", "govt", "Govt.",
        "hv", "HAND", 
        "HR", "HQ", "i.e.",
        "IAM", "IC", "IDC", "IDK", "IM",
        "IMO", "IMHO", "Inc.", "IRL", "ISO", "IT", "J/K", 
        "JK", "Jr.", "KISS", "KPI", "KRA", "L&D",  
        "L8", "L8R", "Lb.", "LLC", "LMAO", "LMK", 
        "LOL", "NP", "NRN", "OIC", 
        "OJT", "OLT", "OMG", "OMW",
        "OTP", "MTD",
        "Max", "MBA", "MBO", "Memo", "Mfg", "min", "Min.", "Mo", "mpt",
        "N.B.", "No", "NSFW", "NWR",
        "p",
        "P&L", "PDF", "Pkg", "PLS", "PLZ", 
        "PM", "PMO", "PO", "POS", "PR",
        "prob", "probs", "PTO",
        "q", "R&D",
        "Q1", "Q2", "Q3", "Q4", 
        "QA", "QoS", "QTY", 
        "RACI", "re:", "Re", "Recd.", "RFP", 
        "ROFL", "ROI", "ROTFL", "ROWE",
        "s/o", "s/t", "SMART", "SNS", "SOHO", "SOOB",
        "STAT", "SWOT",
        "Temp", "tho", "thro",
        "THX", "TMI", "TTYL", "TTYS", 
        "U", "vs",
        "VC", "VLE", "VP", "VPN", "VW", "VWVW",
        "WAH", "WBT", "WIIFM",
        "WFH", "W/", "w/i", "W/O",
        "WB", "WBU", "wrt",
        "YW", "Yr.", "yrs", "YTD" 
    };
    const char * SMSTranslations[189][3] = {
        {"and", "", ""}, {"is", "are", ""}, {"more than", "", ""}, {"less than", "", ""}, {"number", "", ""}, {"times", "", ""}, {"/", "", ""}, {"at", "", ""},
        {"error 404 - not found", "lost", "confused"}, {"US retirement savings plan", "", ""},
        {"account", "", ""}, {"advertisement", "", ""}, {"as far as I know", "", ""}, {"approximately", "", ""}, {"annual percentage rate", "", ""}, {"as soon as possible", "", ""}, 
        {"because", "", ""}, {"business to business", "", ""}, {"before", "", ""}, {"bye for now", "", ""}, 
        {"Bachelor of Business Administration Degree", "", ""}, {"be back later", "", ""}, {"be back soon", "", ""}, {"background", "", ""}, 
        {"be right back", "", ""}, {"Bachelor of Science Degree", "", ""}, {"by the way", "", ""}, {"between", "", ""},
        {"compensation and benefit", "", ""}, {"client and server", "", ""},
        {"Chief Executive Officer", "", ""}, {"Carbon Copy", "", ""}, {"compare", "", ""}, {"Chief Financial Officer", "", ""}, {"company", "", ""}, {"Chief Operating Officer", "", ""}, {"continuity of operations planning", "", ""}, {"corporation", "", ""}, 
        {"compare", "", ""},
        {"customer relationship management", "", ""}, {"customer sales representative", "", ""}, {"contrast", "", ""}, {"Chief Technical Officer", "", ""},
        {"see you", "", ""}, {"see you later", "", ""}, {"see you tomorrow", "", ""}, 
        {"department", "", ""}, {"division", "", ""},
        {"for example", "", ""}, {"Eastern Standard Time"}, {"email service provider", "", ""},
        {"end of day", "", ""}, {"each", "", ""}, {"each", "", ""}, {"end of month", "end of message", ""}, {"end of thread", "", ""}, {"end of year", "", ""}, {"enterprise resource planning", "", ""},
        {"frequently", "often", ""}, {"frequently asked question", "", ""}, {"face to face", "", ""}, 
        {"forward", "", ""}, {"for what it's worth", "", ""}, {"for your information", "", ""}, 
        {"got to go", "", ""}, {"gross domestic product", "", ""}, {"government", "", ""}, {"government", "", ""},
        {"have", "", ""}, {"have a nice day", "", ""}, 
        {"human resources", "", ""}, {"headquarters", "", ""}, {"that is", "", ""},
        {"in a meeting", "", ""}, {"I see", "", ""}, {"I don't care", "", ""}, {"i don't know", "", ""}, {"instant message", "", ""},
        {"in my opinion", "in memory of", "international maritime organization" }, {"in my humble opinion", "", ""}, {"incorporated", "", ""}, {"in real life", "", ""}, {"International Organization for Standardization", "", ""}, {"Information Technology", "", ""}, {"just kidding", "", ""}, 
        {"just kidding", "", ""}, {"junior"}, {"keep it simple stupid", "", ""}, {"key performance indicator", "", ""}, {"key result area", "", ""}, {"learning and development", "", ""}, 
        {"late", "", ""}, {"later", "", ""}, {"pound", "", ""}, {"limited liability company", "", ""}, {"laughing my ass Off", "", ""}, {"let me know", "", ""}, 
        {"laugh out loud", "", ""}, {"no problem", "", ""}, {"no reply necessary", "", ""}, {"Oh, I see", "", ""}, 
        {"on-the-job training", "", ""}, {"online training", "", ""}, {"oh my god", "", ""}, {"on my way", "", ""},
        {"on the phone", "", ""}, {"month-to-date", "", ""},
        {"maximum", "most", ""}, {"Master of Business Administration Degree", "", ""}, {"management by objectives", "", ""}, {"memorandum", "", ""}, {"manufacturing", "", ""}, {"minimum", "least", ""}, {"minimum", "least", ""}, {"month", "", ""}, {"important", "", ""},
        {"note well", "", ""}, {"number", "", ""}, {"not safe for work", "", ""}, {"not work related", "", ""},
        {"after", "", ""},
        {"profit and loss", "", ""}, {"portable document format", "", ""}, {"package", "", ""}, {"please", "", ""}, {"please", "", ""}, 
        {"private message", "project manager", "" }, {"project management office", "", ""}, {"purchase order", "", ""}, {"parent over shoulder", "", ""}, {"public relation", "", ""},
        {"problem", "", ""}, {"problems", "", ""}, {"paid time off", "", ""}, 
        {"every", "", ""}, {"research and development", "", ""},
        {"first quarter", "", ""}, {"second quarter", "", ""}, {"third quarter", "", ""}, {"fourth quarter", "", ""},
        {"quality assurance", "", ""}, {"quality of service", "", ""}, {"quantity", "", ""}, 
        {"responsible, accountable, consulted, informed", "", ""}, {"regarding", "", ""}, {"in regards to", "regarding", ""}, {"received", "", ""}, {"request for proposal", "", ""}, 
        {"rolling On the floor Laughing", "", ""}, {"return on investment", "", ""}, {"rolling on the floor laughing", "", ""}, {"results only work environment", "", ""},
        {"someone", "", ""}, {"something", "", ""}, {"specific, measureable, attainable, realistic, and time-bound", "specific, measureable, achievable, realistic, and time-bound", ""}, {"social network site", "", ""}, {"Small Office", "Home Office", ""}, {"straight out of the box", "", ""}, 
        {"immediately", "", ""}, {"strengths, weaknesses, opportunities, threats", "", ""},
        {"temporary secretary", "", ""}, {"though", "", ""}, {"through", "", ""},
        {"thanks", "", ""}, {"too much information", "", ""}, {"talk to you later"}, {"talk to you soon"}, 
        {"you", "", ""}, {"versus", "against", ""},
        {"Virtual Class", "", ""}, {"Virtual learning environment", "", ""}, {"Vice President", "", ""}, {"Virtual private network", "", ""}, {"virtual worker", "", ""}, {"virtual worker at virtual workplace", "", ""},
        {"Work At Home", "", ""}, {"Web-based training", "", ""}, {"What's in it for me", "", ""},
        {"Work From Home", "", ""}, {"with", "", ""}, {"within", "", ""}, {"without", "", ""}, 
        {"welcome back", "", ""}, {"what about you", "", ""}, {"with respect to", "", ""},
        {"you're welcome", "", ""}, {"year", "", ""}, {"years", "", ""}, {"year-to-date", "", ""}  
    };
    char mi[SIZE] = ""; // message input by user
    char mo[LONG] = ""; // message output 
    int m = 0;          // the method of conversion

    // Enter your message
    printf( "%s :\n", "Enter your message" );
    gets(mi);
    // Choose method of conversion
    printf( "%s", "\nChoose a method: \n 1 - Short message to long\n 2 - long message to short\n? " );
    scanf( "%d", &m );
    // Call the function pointer to the function menu
    (*method[m - 1]) (mi);

} /* end main */
// convert the short message to long message
void sToL( char * message ) {

} /* end function sToL */
// convert the long message to short message
void lToS( char * message ) {

} /* end function lToS */