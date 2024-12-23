//taihu.h
//Sample for room: ������̫��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_taihu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������̫��");
	
	add_npc("pub_youke");       //add by zdn 2001-07-16
	add_npc("pub_qinjinzhe");


	add_door("�����벴����", "�����벴����", "������̫��");
	add_door("��������", "��������", "������̫��");

    set("long", "������Ů����΢Ц���紺���㽿����覡����ֻ�������ʱ��ժ��ʵϷˣ��������������:  '��������ʮ���飬С��̰Ϸ�����١�����Ūˮ��ͷ̲��Ц�Ѻ�ȹ��Ѽ����' �������浭����ɢ�������������" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") 
		&& me->query_temp("wei/renwu5_5") && !me->query_temp("wei/renwu5_7"))
	{
		say("̫�����沨�����ԣ�������������£���ˮ�峺͸�������Կ�������ɫ��С����ˮ����Ȼ��������ȥ��",me);
		AddMenuItem("Ǳ��ȥ", "$0jinru $1", me);
	}
		
	AddMenuItem("�ɺɻ�", "$0cai $1", me);
	AddMenuItem("ժ��Ҷ", "$0zai $1", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!strcmp(comm, "jinru"))
	{
		return do_jinru(me, arg);
	}
	if(!strcmp(comm, "cai"))
	{
		return do_cai(me, arg);
	}
	if(!strcmp(comm, "zai"))
	{
		return do_zai(me, arg);
	}
	return 0;
}

int do_jinru(CChar *me, char * arg)
{
	if(me->query("wei/renwu1") && !me->query("wei/renwu5") && me->query_temp("wei/renwu5_5") && !me->query_temp("wei/renwu5_7"))
	{
		me->move(load_room("������̫������"));
		me->set_temp("wei/renwu5_time",me->query("max_mp")/100);
		me->call_out(do_time, 10);
	}
	return 1;
}

int do_cai(CChar *me, char * arg)
{
	tell_object(me,"$HIR��������ʢ���ĺɻ������̲�ס���ֲ���һ������������");
	load_item("hehua")->move(me);
	return 1;
}

int do_zai(CChar *me, char * arg)
{
	tell_object(me,"$HIR�����������ߣ�����ժ��һƬ��Ҷ����ͷ�ϳ���·�������˹�����");
	load_item("heye")->move(me);
	return 1;
}

static void do_time(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if((me->environment())->query("water"))//��̫��ˮ��
	{
		me->add_temp("wei/renwu5_time",-10);
		if(me->query_temp("wei/renwu5_time")<0)
		{
			char msg[255];
			tell_object(me,snprintf(msg,255, "\n$HIR��о��ؿ�Խ��Խ�ƣ����ɵ��������˿ں�ˮ����������%d���˺���\n",me->query("max_hp")/20));
			me->add("hp",-me->query("max_hp")/20);
			if(me->query("hp")<1)
				me->set("hp",1);
		}
		me->call_out(do_time, 10);
	}
}

ROOM_END;
