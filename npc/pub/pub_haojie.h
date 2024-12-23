// pub_haojie.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_haojie);

virtual void create()
{
	set_name("̫������","taihu haojie" );

	set("icon", young_man2);
	set("gender", "����");
	set("age", 25);
	set("long", "���ǹ���ׯ���µ���̫���ٸ���ƶ��̫�����ܡ�");
	set("combat_exp", 100000);
	set_skill("dodge", 50);
	set_skill("lingxu_bu", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("changquan", 50);
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	map_skill("dodge", "lingxu_bu");
	set("shen_type", 1);
	set_inquiry("����",ask_back);
 	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	return 	"Ҫ�������͸�����....";
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"��λ%s��Ҫ�������͸�����....",query_respect(ob) );
}


static char * ask_back(CNpc * who,CChar *me)
{
	message_vision("����Ⱥ������Ӧ������������ȥ�칦ඣ�\n�������𷫣����������ׯ���С�", me);
	
//	who->call_out(rguiyun, 10 , me->object_id());
	me->move(load_room("�����˺���ͷ"));

	return  "";
}

/*
static void rguiyun( CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

//	CRoom * ship;
//	ship = load_room("/d/guiyun/ship");//û�иó���
	
//	tell_object(who , "ս����һ����������п�������ͷ��" ) ;
//	ship->add_door("����", "�����˺���ͷ",  "��ͷ");
}
*/

NPC_END;