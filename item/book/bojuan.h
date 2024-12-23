//bojuan.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbojuan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

 	set_weight(50);		//set item weight

	set("unit", "��");
	set("long", "���ǿ���ѧϰ��һ��������д�ţ�ׯ�ӡ���ң�Ρ����ƣ��֮����ڤ���ߣ����Ҳ�������ɣ������ǧ�������");
	set("value", 500);
	set("material", "silk");
	set("skill/name","beiming_shengong");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",10);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",19);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn		
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
	{
		 return do_study(me);		 
	}

	return 0;
}

int do_study(CChar *me )
{
	if (me->is_busy()) 
		return notify_fail("��������æ���ء�");
	
	if (DIFFERSTR(me->querystr("family/family_name"), "��ң��")) 
		return notify_fail("��ѧ������ı�ڤ�񹦣������������ң�ɡ�");
	
	if ( me->is_fighting())
		return notify_fail("ս�����޷��Ķ���֪��");

	if ( me->query("hp") > 20 
		&& me->query_skill("beiming_shengong",1) >= 20 
		&& me->query_skill("beiming_shengong",1) <= 100 )
	{
		me->receive_damage("hp", 20);
		me->improve_skill("beiming_shengong", (me->query_skill("beiming_shengong",1)+me->query("int")));
		message_channel("study", "$N����ר���ж���ڤ���ķ���", me);
		return 1;
	}

	return 0;
}

ITEM_END;
