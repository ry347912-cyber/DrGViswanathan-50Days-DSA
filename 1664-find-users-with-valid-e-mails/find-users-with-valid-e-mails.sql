SELECT 
    user_id, 
    name, 
    mail
FROM 
    Users
WHERE 
    mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$'
    -- This enforces that the last 13 characters must exactly be lowercase '@leetcode.com'
    AND RIGHT(mail, 13) = BINARY '@leetcode.com';