//dog
//2001-04-14

ITEM_BEGIN(CIhammer_book);

void create(int nFlag = 0)	
{
	set_name( "���ִ����������о��ο���");	

 	set_weight(200);	

	set("unit", "��");
 	set("long", "������������ʦŷұ����д���飬������������ü��ɶ�������ķ�����");
	set("value",  35000 );
	set("material", "paper");
	set("skill/name","hammer");	
	set("skill/exp_required", 200 );
	set("skill/jing_cost",   10+random(10));
	set("skill/difficulty", 20 );
	set("skill/max_skill", 190 );
	set("skill/min_skill", 25 ); 	

};

ITEM_END;
