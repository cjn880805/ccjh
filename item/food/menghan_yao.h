//menghan_yao.h

//Sample for ITEM �ɺ�ҩ
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImenghan_yao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ɺ�ҩ");	//set item name

	set("long",	"���Ǽ���ͨ���ɺ�ҩ." );
	set("unit", "��");
	set("base_value", 700);
	set("base_unit", "��");
	set("base_weight", 30);
	set_amount(1);

};

virtual int do_use(CChar *me)
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("��Ҫ��˭ʹ�ã�");

	if (me->is_fighting())
		return notify_fail("�����޷�ʹ���ɺ�ҩ��");

	if(me->query_skill("poison",1)<300)
		return notify_fail("��Ķ���̫����ǲ�Ҫ�Եĺá�");

//    if( (me->environment())->query("no_fight"))
//		return notify_fail("��ȫ���޷�ʹ���ɺ�ҩ��");
	
	destruct(this);
	message_vision("\n$N����$nת��ʱ�����ֻ���һ�ڣ�������ָһ����һ����ɫ�ķ�ĩ����ˮ��֮�У�$n����������ں���ˮ����", me, target); 
	
	int i,j; 
	i=me->query_skill("poison",1)-target->query_skill("poison",1); 
	j=me->query("int")-target->query("int");
	if(i>0 && j>-5)
	{ 
		i=10 + i/10; 
		i=i+j;
		if(i<0)i=-i;
		if(EQUALSTR(me->querystr("family/family_name"), "������" ) || EQUALSTR(me->querystr("family/family_name"), "����ɽ��" ))
			i=i*2;
		message_vision("$HIR$N��ǰ������������$n������ҡ����ֻ��$n����Ц�������������죬�����ǲ������������ã����Ǿ�ЪϢһ�ᡭ������$Nҩ�Է���һ��֮�����˹���\n", target,me);  
		target->apply_condition("slumber_drug", i); 
	} 
	else 
	{ 
		i=10 - i/10; 
		if(i<0)i=-i;
		if(EQUALSTR(me->querystr("family/family_name"), "������" ) || EQUALSTR(me->querystr("family/family_name"), "����ɽ��" ))
			i=i/2;
		message_vision("$HIR$N��$n����ҩȴ�ٳٲ�����������ͷ���亹ֱð������֮�¿ڸ������ˮ����һ����һ�Σ�ȴͻȻ���֣��Լ���������ȥ��\n�����ڹر�ǰ���һ��ֻ����$n��Ц�Ŷ��Լ�˵������Ҳ����Ҳ����Ҳ���¶����ֶ����ǳ����Ҳ�������ʹ������������ǰ��Ū������\n", me,target);  
		me->apply_condition("slumber_drug", i); 
	} 
	
	me->start_busy(4);

	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp


