//lu.h
//code by zwb
//12-16

NPC_BEGIN(CNshenlong_lu);

virtual void create()
{

	set_name("½��ͤ","lu gaoxuan");
	set("title", "�����̾�ʦ");
	set("nickname", "�������" );
	set("long", "����ͥ����,������Բ,��ò��ΪӢ��.\nȻ���������,ǡ����̼����ɱ��֮��һ��." );
	set("gender", "����");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_hp", 4500);
    set("hp",1500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("icon",young_man5);	

    set_skill("force", 70);
	set_skill("shenlong_xinfa", 70);
    set_skill("dodge", 70);
	set_skill("yixingbu", 70);
    set_skill("hand", 70);
	set_skill("shenlong_bashi", 70);
    set_skill("parry", 70);
    set_skill("staff", 70);
	set_skill("shedao_qigong", 70);
	set_skill("literate", 220);

	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong_bashi");
	map_skill("parry", "shedao_qigong");
    map_skill("staff", "shedao_qigong");
	prepare_skill("hand", "shenlong_bashi");

	create_family("������",2,"����");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_force", 100);

    set_inquiry("������","һ�������벻���������̵�");
	set_inquiry("�鰲˳","����Ƣ������,Ҫ�������Ĳź�");
	set_inquiry("����","����Ƣ������,Ҫ�������Ĳźá�");
	set_inquiry("�ں�","���겻��!�����ɸ�!��������!������ʥ!");
	set_inquiry("�ؼ�",ask_me);

	carry_object("cloth")->wear();
	add_money(1000);
}


virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "������"))
	{
		say("�㲻�Ǳ��̽���, ����������!",player);
		SendMenu(player);
		return;
	}
	if (player->query_skill("literate",1) < 40 ) 
	{
		say("���ѧ��̫����,����ŬŬ�������һ�°�!",player);
		SendMenu(player);
		return;
	}
	if (player->query("repute") > 0  ) 
	{
		say("�������������������������������ְ׵�����򽻵�������ذɣ�",player);
		SendMenu(player);
		return;
	}

	say("�ܺã��ܺá�");
	command(snprintf(msg,255,"recruit %ld",player->object_id()) );
}

static char * ask_me(CNpc * npc , CChar * player)
{
	CContainer * obj;
	static char msg[255];

	if (DIFFERSTR(player->querystr("party/party_name"), "������") ) 
		return snprintf(msg,255,"%s�뱾��������������֪�˻��Ӻ�̸��",query_respect(player));

	if (npc->query("book_count") < 1)
		return "�������ˣ����̵��ؼ����ڴ˴���";

	npc->add("book_count", -1);

	if (random(2) == 0)
		obj = load_item("shoufa");
	else
		obj = load_item("bufa");
	obj->move(player);

	npc->command(snprintf(msg,255,"rumor %s�õ�%s����",player->name(1),obj->name(1)) );
	return snprintf(msg,255,"�ðɣ��Ȿ��%s�����û�ȥ�ú����С�",obj->query("name"));
}

SHENLONG_END;