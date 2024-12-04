rr = (k, str, sum) => {
    if (k == 0) { 
        if(sum != 7)return;
        console.log(str + " ; "+sum);
        return; 
    }
    for (let i = 1; i <= 6; i++) {
        rec = i + " " +str
        rr(k-1, rec, sum+i)
    }
}
rr(3, "", 0)


rt = (k,v,b,g)=>{
    console.log(k,b)
    rt(k+1,v+k/3+100,b*2,g/3);
}
rt(0," ",4,5)

