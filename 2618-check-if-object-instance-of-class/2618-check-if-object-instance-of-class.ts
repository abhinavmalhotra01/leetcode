function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (obj === null || obj === undefined || typeof classFunction !== "function"){
        return false;
    }
    let curr = obj;
    if(typeof obj !=="object"){
        curr = Object(obj);
    }
    return curr instanceof classFunction;
}

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */