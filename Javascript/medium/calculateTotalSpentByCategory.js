function calculateTotalSpentByCategory(transactions) {
    let mpp=new Map();
    for(let i=0;i<transactions.length;i++){
        if(mpp.get(transactions[i].category)){
            mpp.set(transactions[i].category,mpp.get(transactions[i].category)+transactions[i].price);
        }
        else{
            mpp.set(transactions[i].category,transactions[i].price);
        }
    }
    let arr=[];
    for([Key,value] of mpp){
        arr.push({category:Key,totalspent:value});
    }
    console.log(arr);


}
let transactions=[
  {
    id: 1,
    price: 10,
    category: "Food"
  },
  {
    id: 2,
    price: 20,
    category: "Food"
  },
  {
    id: 3,
    price: 15,
    category: "Travel"
  }
]
 calculateTotalSpentByCategory(transactions);
