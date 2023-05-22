function jsonStringify(object: any): string {
    if(object===null){
        return 'null';
    }
     if(Array.isArray(object)){
        const curr2 = object.map((c1:any)=> jsonStringify(c1));
        return `[${curr2.join(',')}]`;
    }
    if(typeof object ==='object'){
        const keys = Object.keys(object);
        const curr =keys.map((key:any)=>`"${key}":${ jsonStringify(object[key])}`);
        return `{${curr.join(',')}}`;
    }
    if(typeof object ==='string'){
        return `"${object}"`;
    }
    return String(object);
};