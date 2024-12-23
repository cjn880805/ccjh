//po_bu.h
//丐帮物件
//lanwood 2001-01-06

ITEM_BEGIN(CIpo_bu)

virtual void create(int nFlag = 0)		
{
	set_name("破布", "po bu");
    set_weight(80);
        
    set("unit", "块");
    set("long","这是一块破布，凭此可直接向简长老要求升袋。");
    set("material", "cloth");
        
};

ITEM_END;
