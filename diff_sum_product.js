/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let product = 1;
    let digi_sum = 0;
    
    //Checks the length of the number, not so necessary but I did it after all
    if(n.length == 1){
        return n - n ;
    }else{
        String(n).split("").forEach((digit)=>{
            product = product * parseInt(digit);
            digi_sum = digi_sum + parseInt(digit);
        })

        return product - digi_sum;
    }
};