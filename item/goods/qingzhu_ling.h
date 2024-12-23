//qingzhu_ling.h
//丐帮物件
//lanwood 2001-01-06

ITEM_BEGIN(CIqingzhu_ling)

virtual void create(int nFlag = 0)		
{
	set_name("青竹令", "qingzhu ling");
    set_weight(500);
                
    set("unit", "面");
    set("long","这是一块用青竹做成的令牌,由九袋长老简长老签发,凭此牌弟子可自由向同门大师兄挑战。");
    set("value", 0l);
    set("material", "steel");    
        
};

ITEM_END;
