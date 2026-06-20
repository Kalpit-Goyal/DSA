function isAnagram(str1, str2) {
    let mpp=new Map();
    for(let i=0;i<str1.length;i++){
        if(mpp.get(str1[i])){
            mpp.set(str1[i],mpp.get(str1[i])+1);
        }
        else{
            mpp.set(str1[i],1);
        }
    }
    for(let i=0;i<str2.length;i++){
        if(mpp.get(str2[i])>0){
            mpp.set(str2[i],mpp.get(str2[i])-1);
        }
        else{
            return false;
        }
    }
    for(let [key,value] of mpp){
        if(value!=0){
            return false;
        }
    }
    return true;


}
let str1="fwefgegewgwe";
let str2="fwefgegewhgyujgwe";
console.log(isAnagram(str1,str2));

