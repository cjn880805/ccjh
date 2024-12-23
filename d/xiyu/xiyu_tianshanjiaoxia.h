//tianshanjiaoxia.h

//Sample for room: ��ɽ����
//coded by zwb
//data: 2000-11-21

XIYU_BEGIN(CRXiYu_tianshanjiaoxia);

virtual void create()		
{
	set_name( "������ɽ����");
	
	add_npc("monster_8k");         //add by zdn 2001-07-16

	add_door("�����Ͻ�ɳĮ", "�����Ͻ�ɳĮ", "������ɽ����");
	add_door("������ɽɽ·1", "������ɽɽ·1", "������ɽ����");
	add_door("����˿��֮·1", "����˿��֮·1", "������ɽ����");

	call_out(do_thing,1200);	

};

static void do_thing(CContainer * ob, LONG param1, LONG param2)
{
	switch(ob->query_temp("thing"))
	{
	case 0:
		tell_room(ob,"\n$HIC��ӯ��ѩ��������Ϣ�����Ʈ�裬һƬһƬ���׷����\n");
		ob->set("index",2);
		ob->add_temp("thing",1);
		ob->call_out(do_thing, 60);	
		break;
	case 1:
		tell_room(ob,"\n$HIC�����ѩ����ؼ��ããһƬ���ֲ��������죬���ǵء�\n");
		ob->add_temp("thing",1);
		ob->call_out(do_thing, 60);	
		break;
	case 2:
		tell_room(ob,"\n$HIC�����ˣ�ѩͣ�ˣ��������⴩͸�����Ʋ�����������������ѩ���������ҫ�£��������������⡣\n");
		ob->delete_temp("thing");
		ob->del("index");
		load_item("xueduei")->move(ob);
		ob->call_out(do_thing, 3600);
		break;
	}
}

XIYU_END;
