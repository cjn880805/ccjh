
AUTOCOMBINE_BEGIN(CItradepro_item);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�������", "cai liao");	//set item name

	set_weight(1000);		//set item weight

	set("long", "��������������Ҫ�Ĳ��ϡ�");
	set("unit", "��");
	set("value", 1);
	set("base_unit", "Ƭ");
	set_amount(1);
};


AUTOCOMBINE_END;



