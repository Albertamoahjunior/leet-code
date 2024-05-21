class Solution {
public:
    std::string processEmail(const std::string &email) {
        size_t at_position = email.find('@');
        std::string local = email.substr(0, at_position);
        std::string domain = email.substr(at_position);
        
        // Remove dots from the local part
        local.erase(std::remove(local.begin(), local.end(), '.'), local.end());
        
        // Ignore everything after the first plus
        size_t plus_pos = local.find('+');
        if (plus_pos != std::string::npos) {
            local = local.substr(0, plus_pos);
        }
        
        // Combine local and domain
        return local + domain;
}

    int numUniqueEmails(vector<string>& emails) {
         std::unordered_set<std::string> uniqueEmails;
    
        //set up a for loop to insert the processed emails into a set
        for (const std::string& email : emails) {
            uniqueEmails.insert(processEmail(email));
         }
        
        //return the number of the emails left in the set as the final answer
        return uniqueEmails.size();
    }
};
