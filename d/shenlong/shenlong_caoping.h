//caoping.h

//Sample for room:  �����̲�ƺ 
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_caoping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̲�ƺ");
	
	add_npc("shenlong_old");
	add_npc("shenlong_girl");          //add by zdn 2001-07-20

	add_door("�����̿յ�", "�����̿յ�", "�����̲�ƺ");
};

virtual int do_look(CChar * me)
{
	if(me->query_temp("wei/renwu4_5")  )
	{
		say("��ʯ���У�¶��һ���ں����Ķ��ڡ�",me);
		CContainer * baishu=me->present("bai shu");
		if(baishu)
		{
			AddMenuItem("����С����","$0baishu $1",me);
		}
		SendMenu(me);
	}
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("wei/renwu4_5") )
		return 0;
	if (me->query_temp("wei/renwu4_6") )
		return 0;
	if(!strcmp(comm, "baishu"))
	{
		CContainer * baishu=me->present("bai shu");
		if(baishu)
		{
			baishu->move(me->environment());
			baishu->set("owner",me->id(1));
			me->set_temp("wei/renwu4_6",1);//�����˰���
			((CChar *)baishu)->call_out(do_yingsheng, 30);
		}
		return 1;
	}
	return 0;
}

static void do_yingsheng(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			tell_object(me, "$HIR\nͻ��һ����ľ����Ӷ��д��˳���������Ѫ���ڣ���о����֮�䣬�ȳ��˱ǡ�");
			tell_object(me, "$HIRС�����ŵ����ĺ���������鴤��������ֲ��ĳ������㼸���赽��");
			tell_object(me, "$HIR�㾪��֮�䣬��֪������Ǻã�����\n");
			CNpc * she = load_npc("qishe");
			((CChar *)she)->set("owner",me->id(1));
			((CChar *)she)->move(env);
			((CChar *)she)->call_out(do_pao, 10);
			tell_object(me, "\n$HIRޭ��������ϸ�Ĵ������㣡");

			CContainer * xionghuang=me->present("xionghuang");
			if(xionghuang)
				tell_object(me, "$HIRޭ����ͼ�������������������Ϻ������������µĶ�����");
			else
				((CChar *)she)->kill_ob((CChar *)me);
		}
		destruct(npc);
	}
}

static void do_pao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0] && !npc->is_fighting())
	{
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
			tell_object(me, "$HIR\nޭ���㬵����ض��У����ʧ�˳���������ȡ��ޭ�ߵ���������\n");
		destruct(npc);
	}
}
ROOM_END;
//last, register the room into ../server/RoomSetup.cpp