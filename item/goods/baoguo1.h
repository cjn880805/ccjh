ITEM_BEGIN(CIbaoguo1);

virtual void create(int nFlag = 0)		
{
	set_name("������","bao guo");	
	set_weight(20000);
};

virtual int do_look(CChar * me)
{
	say("һ���ô�첼���ŵİ�������֪������װ����ʲô��", me);
	SendMenu(me);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		if(querystr("owner")[0])
		{
			if(EQUALSTR(querystr("owner"), me->id(1)))
			{
				if(me->query("xkd/wei")==500)
				{
					load_item("tiancanbaojia")->move(me);
					tell_object(me,"������װ�úܲ�����ʵ����ò����ײŴ򿪰�������������װ�ľ�Ȼ��һ����ϱ���");
					me->del("xkd/wei");
				}
				else if(me->query("xkd/wei")==200)
				{
					load_item("xuantiebishou")->move(me);
					tell_object(me,"��򿪰�������������װ����һ���������������ذ�ס�");
				}
				else if(me->query("xkd/wei")==50)
				{
					load_item("38huoqiang")->move(me);
					tell_object(me,"��򿪰�������������װ��һ�Ѿ��µĵ����˻�ǹ��");
				}
				else
				{
					char msg[255];
					if(random(2))
					{
						me->add("combat_exp",3000+me->query("xkd/wei")*50);
						me->UpdateMe();
						tell_object(me,snprintf(msg, 255,"����˰�����������һЩ���߽������ĵã�����������%d�㾭�飡��\n",3000+me->query("xkx/wei")*100));
					}
					else
					{
						CContainer * bot = load_item("yinpiao1");
						bot->set("value", 200000+me->query("xkd/wei")*100);
						bot->move(me);
						tell_object(me,snprintf(msg, 255,"��򿪲�������ȴ��������װ����һ��%d������Ʊ��",200000+me->query("xkx/wei")*1000));
					}
				}
			}
		}
		destruct(this);
		return 1;
	}

	return notify_fail("�������ܶԱ���ʹ�á�");
}

ITEM_END;

