//��ʱ��
//yanshiling.h

ITEM_BEGIN(CIyanshiling);

virtual void create(int nFlag = 0)		
{
	char msg[80];

	set_name("������", "yan yu ling");
	set("value", 1);
	set("weight", 100);

	int level = nFlag;

	if(! nFlag) level = random(20) + 1;
	set("long", snprintf(msg, 80, "����һ��ī��ɫ�����ƣ�ʹ�ú�����ӳ�%d���ӵ�����ʱ�䡣", level));
	set("protect", level);

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("mp")<50)
	{
		tell_object(me, "��ķ���������");
		return 0; 
	}

	me->add("mp", -50);
	if(me->query("level")>=60 && me->querymap("tradepro") )
	{
		if(me->query("tradepro/quest_time")>current_time)
		{
			char msg[255];
			tell_object(me, snprintf(msg, 255, "$HIG�㵱ǰ�ġ��̽���������������ʱ���ӳ���$HIR %d $HIG���ӡ�",query("protect")));
			me->add("tradepro/quest_time",query("protect")*60);
		}
		else
		{
			tell_object(me, "$HIG�ܿ�ϧ��������̫���ˣ���ġ��̽������������Ѿ������ˡ�");
			return 0; 
		}
	}
	else
	{
		tell_object(me, "$HIG�������ó�����ʹ�����������~~~~~��û�ˣ�");
	}
	destruct(this);
	return 1; 
}

ITEM_END;




