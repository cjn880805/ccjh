//xin.h 

ITEM_BEGIN(CItongxinyin)

virtual void create(int nFlag = 0)		
{
	 set_name("ͬ��ӡ", "concentric mark");
     set_weight(100);
        
     set("unit", "��");
     set("material", "steel");
 	 set("no_get",1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	char msg[255];
	if (EQUALSTR(me->querystr("gender"), "����"))
		return notify_fail("����̫��Ҳ�롭����");


	if (!querystr("teapot/male")[0] && EQUALSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("ͬ��ӡ��������û�б���������");					// ???

	if (querystr("teapot/male")[0] && EQUALSTR(me->querystr("gender"), "����"))
		return notify_fail("�������������ͬ�������������ʱ������");		// ???

	if ((me->query("age") < 18) && EQUALSTR(me->querystr("gender"), "����")
		|| (me->query("age") < 16) && EQUALSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("̫С�˵�ɡ�������÷����Ҳ������ô�ż�����");


	if (me->is_busy())
		return notify_fail("�����ں�æ��");
	if( me->is_fighting() )
		return notify_fail("���Ȼ������������������˵�ɡ�");
	if( EQUALSTR(me->querystr("class"), "bonze"))
		return notify_fail("���С������С���");
	//if( EQUALSTR(me->querystr("class"), "taoist" ))
	//	return notify_fail("��ʿҲ��飿");
	
	if( me->querymap("couple"))	
		return notify_fail("�㲻ר�飬ͬ��ӡ�����㡣");
	
	if( me->query("couple_betray") > 1 )	
		return notify_fail("�㲻ר�飬ͬ��ӡ�����㡣");
	
	if (!querystr("teapot/male")[0])
	{
		set("teapot/male",me->querystr("id"));
		set("teapot/malename",me->querystr("name"));
		message_vision("$N����Ľ��ָ�����ͬ��ӡ�ϣ�����͵�Ŀ�⿴�ż�ӡ����",me);
		message_vision("ֻ��ͬ��ӡ������ɢ�����������ٻ�ɫ��â����",me);
		set_name("ɢ���ŵ���΢���ͬ��ӡ");
		remove_call_out(remove_telepathy);
		call_out(remove_telepathy, 30);
		return 1;
	}

	CContainer * obj;
	obj=me->environment();

	CChar * player1;
	player1=(CChar * ) obj->present(querystr("teapot/male"));

	if(!player1 )
	{
		return notify_fail("��ò������¶����ģ����ǡ������أ�");
	}

	//if (EQUALSTR(player1->querystr("id"), me->querystr("last_couple_id")))
	//{
	//	return notify_fail("ͬ��ӡ�����¸¡��������ǲ��ǲ������");
	//}

		remove_call_out(remove_telepathy);
		
		set("teapot/female",me->querystr("id"));
		set("teapot/femalename",me->name(1));
		message_vision("$N�����۾���΢΢�³�һ���������ַ���ͬ��ӡ�ϡ���",me);
		message_vision("ֻ��ͬ��ӡ������ɢ����������ǳ��ɫ��â����",me);
			
		g_Channel.do_channel(&g_Channel, 0, "news", 
				snprintf(msg, 255, "%s��%s����ָ��Ϊ�ģ�����Ϊ�ˣ�����ͬ�ģ�������������Υ��Լ����", querystr("teapot/femalename"),querystr("teapot/malename")));

		//Modified by lanwood 2001-03-15
		me->set("couple/id", player1->querystr("id"));
		me->set("couple/name", player1->querystr("name"));
		me->set("couple/gender", "�Ϲ�");

		player1->set("couple/id", me->querystr("id"));
		player1->set("couple/name", me->querystr("name"));
		player1->set("couple/gender", "����");

		player1->set_temp("teapot/m_m", 1);	//���Է�����ı��

		/*
		me->set("teapot/marry",querystr("teapot/male").c_str());
		me->set("teapot/marryname",querystr("teapot/malename").c_str());

		player1->set("teapot/marry",querystr("teapot/female").c_str());
		player1->set("teapot/marryname",querystr("teapot/femalename").c_str());		
		*/

		message_vision("ɲ�Ǽ�һ�������չ���ͬ��ӡ����һ˿���̶�ȥ��ֻ��������������������á����˼���Ե���ϣ������ֶ�һ�ʣ�",me);

		destruct(this);

	return 1;


//���ܲ��ܸı�channel�ķ����ߣ���Ҫ��Ƶ�����顱��


}




static void remove_telepathy(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	ob->del("teapot/male");
	ob->del("teapot/malename");
	ob->set_name("ͬ��ӡ");

	if(userp(me))
		tell_object((CChar *)me, "ͬ��ӡ�Ĺ�â�����������ˡ���");
	else
		tell_room(me, "ͬ��ӡ�Ĺ�â�����������ˡ���");

//	destruct(ob);
	return;
}






ITEM_END;







// �������� �������� ����춰� ���Ǻβ�