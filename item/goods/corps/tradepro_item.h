
AUTOCOMBINE_BEGIN(CItradepro_item);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "任务材料", "cai liao");	//set item name

	set_weight(1000);		//set item weight

	set("long", "这是任务中所需要的材料。");
	set("unit", "把");
	set("value", 1);
	set("base_unit", "片");
	set_amount(1);
};


AUTOCOMBINE_END;



