ITEM_BEGIN(CItie_ling)

virtual void create(int nFlag = 0)		
{
	set_name("重阳令", "chongyang ling");
	set_weight(100);
	set("unit", "块");
    set("long", "这是一块用于通行重阳宫的铁铸令牌。 由丹阳真人签发，邀各路英雄入宫观礼。");
	set("value", 100);
	set("material", "iron");

	call_out(do_dest, 1800);
};

static void do_dest(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

ITEM_END;
