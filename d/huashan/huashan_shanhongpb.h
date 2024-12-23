//shanhongpb.h

//Sample for room: ��ɽɽ���ٲ�
//coded by zouwenbin
//data: 2000-12-2
//Last modify @ 2001-03-08
//by Teapot
//��ɽ������

ROOM_BEGIN(CRHuaShan_shanhongpb);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ���ٲ�");

	add_door("��ɽɯ��ƺ", "��ɽɯ��ƺ", "��ɽɽ���ٲ�");

	set("long", "������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵��ٲ�����˵�������������������������ɾ��������������ġ�������ȥ�ȿգ�ֻʣ�¿��ȵ�ɽ�Ⱥͱ��ڵĺ�ˮ(hongshui)��");  

};

virtual int do_look(CChar * me)
{
	say("������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵��ٲ�����˵������²��ܾ��������������ġ�������ȥ�ȿգ�ֻʣ�¿��ȵ�ɽ�Ⱥͱ��ڵĺ�ˮ��", me);
	AddMenuItem("����", "$0forsake $1", me);
	AddMenuItem("��������", "", me);
	if(me->query("level")>45 && EQUALSTR(me->querystr("family/family_name"), "��ɽ��") //�ȼ�����45����ѧ����¾Ž��Ļ�ɽ���ӿ��Դ���������
		&& !me->query_temp("was/renwu1_1") && me->query_skill("lonely_sword",1))
	{
		AddMenuItem("����", "$0lianjian $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(me->query("level")>45 && EQUALSTR(me->querystr("family/family_name"), "��ɽ��") 
		&& !me->query_temp("was/renwu1_1") && me->query_skill("lonely_sword",1))
	{
		if(!strcmp(comm, "lianjian") )
			return do_lianjian(me, arg);
		else if(!strcmp(comm, "pishi") )
			return do_pishi(me, arg);
	}
	if(strcmp(comm, "forsake") == 0)
	{
		DTItemList * list = me->Get_ItemList();
		CContainer * item = 0;
		POSITION pos;
		int flag = 0;
										
		pos = list->GetHeadPosition();
		while(pos)
		{
			item = list->GetNext(pos);
			if (item->query("teapot/brand")==1)
			{
				flag = 1;
				break;
			}	
		}
	
		if (!flag || ! item)
		{
			return notify_fail("ԭ�޽����������");				
		}
		
				
		message_vision("$N��Хһ����������$n�������ɽ�飬ɲʱ��������", me, item);
		DESTRUCT_OB(item, "huanshan_shanhongpb");
		
		me->set("teapot/cumpower",0l);
		me->add("teapot/referent",-1);
		me->Save();
		
		return 1;
	}

	return 0;
}

int do_lianjian(CChar *me, char * arg)
{
	say("��һ������մ̣���������������ˮ���಻������",me);
	say("��Ȼ�䣬�㿴��Զ���ٲ���·��и�����������ʩչ�Ṧ������һԾ���ٲ��׶ˣ���һ��һ��������Ծ��",me);
	say("ͻȻ��������һ��������һ��ʯ��˳�ٲ��������������",me);
	AddMenuItem("��ʯ", "$0pishi $1", me);
	SendMenu(me);
	return 1;
}

int do_pishi(CChar *me, char * arg)
{
	say("�����ֳ�������佣������ƥ���⼲����ʯ��",me);
	say("��ʯת�۱��������Ը��޷��ԾŽ��е��κ�һ����֮����",me);
	
	if(me->query_skill("lonely_sword",1)>200 &&
		(me->query_skill("feiyan_huixiang",1)>150||me->query_skill("huashan_shenfa",1)>150))
	{
		say("������ʱ��Ľ����Ѿ�¯���࣬���پ����ڽ��С������㰵��ڤ�룬����ͬʱ�������������������������һ������ʯ�������롣",me);
		say("���������ڣ�����һյ�蹤���Ծ���ٲ���Ķ��ڡ�",me);
		me->move(load_room("��ɽ�ٲ���ɽ��"));
		me->set_temp("was/renwu1_1",1);//����������������
	}
	else
	{
		say("����ͼ�Դ�������ʯ��Ȼ�����������ֻ����ʯ������װ����������壬���ʮ�ɸߵĵط��������ٲ��ף���ʱ���ʹ�ȥ��",me);
		me->unconcious();
	}
	SendMenu(me);
	return 1;
}
ROOM_END;
