//sacred_fruit.h ���

FOOD_BEGIN(CIsacred_fruit);

virtual void create(int nFlag = 0)		
{
	set_name("���");	

	set_weight(20);
	set("unit", "��");
	set("long","����һ�������ͨ���ʺ죬һ����֪�ǲ��ɶ�õ���Ʒ!");
	set("value", 10000);
};

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	int exp=0;
	if(query("max"))
		exp=random(query("max"));

	if(random(10000)==250)
		exp=-exp;
	if(me->query("age")<24 || me->query("level")<45)//��������24�����£��ȼ�45������ʹ����Ч��
		exp=0;
	me->add("add_hp",exp);
	me->add("max_hp",exp);
	me->add("eff_hp",exp);
	me->add("hp",exp);
	me->UpdateMe();
	
	if(exp>0)
	{
		g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIC%s(%s)����һ��$HIR���$HIC��ֻ������ȫ����һ��ů���ӵ���ֱ��������$COM", me->name(1),me->id(1)));
		message_vision("$N����һ�������ֻ������ȫ����һ��ů���ӵ���ֱ��������$HIR$N��HP��������ˣ�", me);
		tell_object(me,snprintf(msg, 255,"��ģȣ����������%d�㣡",exp));
	}
	else if(exp <0)
	{
		g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIC%s(%s)����һ��$HIR���$HIC��ֻ���øγ���ϣ��������ѡ�$COM", me->name(1),me->id(1)));
		message_vision("$N����һ�������ֻ���øγ���ϣ��������ѡ�$HIR$N��HP�����½��ˣ�" , me);
		tell_object(me,snprintf(msg, 255,"��ģȣ������½���%d�㣡",-exp));
	}
	else 
		message_vision("$N����һ�������ֻ������ȫ����һ��ů���ӵ���ֱ��������", me);
    destruct(this);
    return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp