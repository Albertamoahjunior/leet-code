/**
 * @param {string[]} operations
 * @return {number}
 */
var calPoints = function(operations) {

    //initializing variables to be used
    let result_list = [];
    let curr_pos = 0;
    let result = 0;

    // loop through to gather integers and perform operations
    for(let i = 0; i < operations.length; i++){
        let temp = operations[i];


        if(parseInt(temp)){
           result_list.push(parseInt(temp))
           curr_pos += 1;
        }else{
            switch (temp){
                case 'C':
                    result_list.pop();
                    curr_pos -= 1;
                    break;
                case 'D':
                    result_list.push(result_list[curr_pos -1] * 2);
                    curr_pos += 1;
                    break;
                case '+':
                    result_list.push(result_list[curr_pos -1] + result_list[curr_pos -2]);
                    curr_pos += 1;
                    break;
            }
        }
        
        
        }

    //finally add all the elements in the resulting list for your final result.
    for(let i = 0; i < result_list.length; i++){
        result += result_list[i];
    }

    return result;
};