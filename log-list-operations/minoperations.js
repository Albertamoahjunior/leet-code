/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let minjump = 0;

    for(let i= 0; i<logs.length; i++){
        switch(logs[i]){
            case './':
                minjump += 0;
                break;
            case '../':
                if(minjump){
                    minjump -= 1;
                }
                break;
            default:
                minjump += 1;
                break;
        }
    }

    return minjump;
};
