//duanqiao.h
//Sample for room: ���ݶ���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_duanqiao);

virtual void create()
{
	set_name( "���ݶ���");

	add_npc("pub_poorman");
	
	add_door("������ʯ���9", "������ʯ���9", "���ݶ���");
	add_door("���ݰ׵�", "���ݰ׵�", "���ݶ���");

	set("long"," �������������������ķ�ˮ���ϡ�����ͤ�����䣬��ӳ����������֮�¡���ɽ��ˮ����������������������������������������ľ�ɫ���ڶ����Ͽ����������ɽ�ͺ�����ķ�⡣ÿ��ѩ�ᣬվ����ͷ��ֻ��һ�ж������ϰ�ѩ��������¥�ĺ�ɽ��ò��������ʮ��֮һ�ġ����Ų�ѩ��������񻰡����ߴ����еİ���������ɾ����������ġ�    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");
	call_out(do_thing, 5);	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

static void do_thing(CContainer * ob, LONG param1, LONG param2)
{
	switch(ob->query_temp("thing"))
	{
	case 0:
		tell_room(ob,"\n$HICһ��������棬Ƭ�̣�С������������������\n");
		ob->add_temp("thing",1);
		ob->set("index",1);
		ob->call_out(do_thing, 60);	
		break;
	case 1:
		tell_room(ob,"\n$HIC��Խ��Խ�����������µ�������ڵ��Ͻ���һ��侧Ө��ˮ����");
		tell_room(ob,"$HICԶ��Ⱥɽ����������������һ��ˮī����\n");
		ob->add_temp("thing",1);
		ob->call_out(do_thing, 60);	
		break;
	case 2:
		tell_room(ob,"\n$HIC�꽥��ͣ�ˣ��α̵���߳���һ�������Ĳʺ硣΢�紵�������µ���Ϣ���������\n");
		ob->delete_temp("thing");
		ob->del("index");
		ob->call_out(do_thing, 3600);	
		break;
	}
}

ROOM_END;
