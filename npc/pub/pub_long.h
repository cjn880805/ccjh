//pub_long.c

// code by Fisho
// date:2000-12-17
//inherit F_MASTER;

NPC_BEGIN(CNpub_long);

virtual void create()
{
	set_name("������", "long");

	set("icon", young_man6);
	set("long", "������������֮ɫ������͵��������ųơ�������������üȫ�ף���ɫ�������红ͯ������������ʵ����͡�");
	set("title", "���͵���");
	set("gender", "����");
	set("age", 75);
	set("nickname",   "����"  );
	set("shen_type",1);
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);
	
	set("hp", 900);
	set("max_hp", 2700);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set_skill("force", 170);
	set_skill("unarmed", 100);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",170);
	set_skill("staff", 170);
	set_skill("jinwu_daofa", 150);
	set_skill("lingxu_bu", 150);
	
//  set_skill("yanyangong", 200);
//  set_skill("xiake_zhangfa", 100);
//  map_skill("force", "yanyangong");
//  map_skill("unarmed", "xiake_zhangfa");
//  map_skill("hand", "xiake_zhangfa");
//	map_skill("dodge", "lingbo_weibu");
	map_skill("parry", "jinwu_daofa");
	map_skill("staff", "jinwu_daofa");
	
	create_family("���͵�",1, "����");
	set_inquiry("������","������ֻ����Ե�ˣ���֪���Ƿ�������������");
	set_inquiry("ͭ��","�����û�������գ�������Ҫ�Ļ������ұ�����һ�ʡ�");

	carry_object("gangdao")->wield();
	add_money(2000);
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	message_vision("����������$N��ͷ��΢΢ҡ��ҡͷ��",ob);
	return;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obn;
//	CContainer * room;
	CContainer * key;
	char msg[255];
	
	if(  DIFFERSTR(ob->querystr("name"), "����ͭ��") )
	{
		message_vision("�Ҳ���Ҫ���������",who);
		return 0;
	}
	if (  DIFFERSTR(ob->querystr_temp("own"),  who->querystr("name")) )
	{
		message_vision("�ⲻ��������ӡ�",who);
		return 0;
	}

	say(snprintf(msg,255,"ԭ����%s������ӭ���ٱ�����", who->name()));
	
	obn=load_item("labazhou");//������
	obn->move(who);
	say(snprintf(msg,255," ���Ǳ����ز������࣬��߿ɲ��׺ȵ�����������Ҫ��һζ��<�ϳ�ʴ�Ǹ��Ĳ�>�� ��%sҲ����Ե֮�ˣ�����Ⱥȣ�����Ч��������",query_respect(who) ));
	
	if(  who->query_temp("zhou") == 2)
	{
		say(" ������ʿ��Ե����л���һ�����־���������ɣ�");
		who->set_temp("zhou", 0l);
		message_vision("ֻ����һ��¡¡��������Զ������", who);
		message_vision("ֻ����������ʯ�建�����˿�����¶��һ������������", who);
		//(who->environment())->set("exits/enter", "/d/xiakedao/mishi");

		//room = who->environment();
		//remove_call_out(close);
		//call_out(close, 15, room->object_id());
		key = load_item("key");//û�и���Ʒ
		message_vision("���������ʯ�ŵ�Կ�ף�Ҳ�����͵��ϵ�ƾ֤��ϣ�������Ʊ��ܣ��������ⶪ���������ɽ������ˣ��뵺ʱӦ��黹��", who);
		key->move(who);

		//who->move(Load_Room"���͵�����");
		return 1;
	}

	who->set_temp("zhou", 1);
	return 1;
}
/*
static void close(CContainer *ob,LONG param1,LONG param2)
{
	CChar *me = (CChar *)(ob->environment())->Present(param1);

	if (!me) return ;
	tell_room(me->environment(),"��¡¡���������֮��ʯ���ֺ����ˡ�", me);
	me->del("exits/enter");
}
*/

NPC_END;