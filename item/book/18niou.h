//18niou.h

//Sample for ITEM: ʮ����ż
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CI18niou);

void create(int nFlag = 0)		
{
	set_name( "ʮ����ż");	

	set_weight(600);		

	set("unit", "��");
	set("long", "����һ��Сľ�У����в���������������ż��ÿ������������һʮ�˸���������");
	set("value", 5000);
	set("material", "mud");
	set("skill/name","force");	
	set("skill/exp_required",0l);
	set("skill/jing_cost",30);	
	set("skill/difficulty",20);	
	set("skill/max_skill",59);	
	set("skill/min_skill",30);  

};

int do_look(CChar * me)
{
	CItem::do_look(me);

	if(environment() == me)
	{
		AddMenuItem("����", "$0nie $1", me);
		AddMenuItem("ֹͣ�۲�", "", me);
		SendMenu(me);
	}
	
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "nie") == 0)
		return do_nie(me);
	return 0;
}

int do_nie(CChar * me)
{
	if(environment() != me) return 0;
	if(query_temp("yongren/rent"))return 0;

	load_item("18muou")->move(me);

	message_vision("$N����һ��ˢˢˢ������������������ķ��Ρ��Ͳʺ���׷׷׵��䡣¶��һ�������ľż����", me);
	
	destruct(this);
	return 1;
}

ITEM_END;
