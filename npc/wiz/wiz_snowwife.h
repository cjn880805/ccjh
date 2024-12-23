//snowwife.h
//����NPC
//lanwood 2001-04-20

/*
	ѩ������Ѱ��999��õ�廨��
*/

NPC_BEGIN(CNwiz_snowwife);

void create()
{
	set_name("ѩ��", "snow girl");
	set("long", "һ������ȥ�����ĵ�Ů���ӡ�");
	set("icon", young_woman2);
	
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");
		
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 1000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("hubo", 300);
	set_skill("literate", 100);
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 200);
	set_skill("lingxu_bu", 200);
	set_skill("wudu_xinfa", 200);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
		
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

int do_talk(CChar *me, char * ask)
{
	if(! me->querymap("coupler"))
	{
		say("�㻹û���������ˣ�������������ĵ�ʹ�ࣿ", me);
		SendMenu(me);
		return 1;
	}

	if(EQUALSTR(me->querystr("gender"), "����"))
	{
	}
}

void relay_emote(CChar *me, string verb)
{
	if(DIFFERSTR(me->querystr("couple/gender"), "�Ϲ�" ))
		return;

	if(verb == ":(" || verb == "cry")
		me->add_temp("pending/ѩ��", 1);

	if(me->query_temp("pending/ѩ��") == 5)
	{
		command(snprintf(msg, 255, "cry1 %ld", me->object_id()));
		//Ҫ����
		say("Ϊ�μ����������ᣬΪ�μ����Ȼ��ʧ������ĺ�ʹ���ǰɡ��Ȳ����ᡣ", me);
		say("�������Ŀࡣ��Ҳ���ɷ�", me);
		say("��ǰ������һ��ɱ����һ������������Ҳ���ȹ����õ�ʱ�⡣", me);
		say("ֱ����һ�죬��������ҵ����⣬��Ȼ�뿪���������ݵļҡ�");
		say("����������������ǰ�������̣��������ĵ�������������ʼ�ҹ������߽������ọ́�ȥ��������", me);
		say("�������������ֵ�ʱ��ͻȻ������ʲô��", me);
		say("�Ӵˣ��ҿ��������������ޣ���û�����ҵ�����������", me);
		AddMenuItem("��οѩ��", "$0comfort $1", me);
		AddMenuItem("����������", "", me);

		me->set_temp("pending/ѩ��", 100);
		SendMenu(me);
		return;
	}

	if(verb == "comfort" && me->query_temp("pending/ѩ��") == 100)
	{
		say("��һ����ͻȻ���������֣����һؼҡ�", me);
		say("Ȼ�������������޿���ء���", me);
		AddMenuItem("�㰡��һ��", "$0ah", me);
		AddMenuItem("����������", "", me);

		me->set_temp("pending/ѩ��", 200);
		SendMenu(me);
		return;
	}

	if(verb == "ah" && me->query_temp("pending/ѩ��") == 200)
	{
		say("��������������ҹ������Ҷ���˵����", me);
		say("���뿴�����õ�塭��", me);
		say("���뿴����ı�������", me);
		say("���뿴����İٺϡ���", me);
		say("���뿴����������ǡ���", me);
		say("���ܸ�����");
		
		AddMenuItem("�㰡��һ��", "$0ah", me);
		AddMenuItem("����������", "", me);

		me->set_temp("pending/ѩ��", 300);
		SendMenu(me);
		return;
	}

	if(verb == "ah" && me->query_temp("pending/ѩ��") == 300)
	{
		say("��ͷҲ���ص����ˡ�", me);
		say("һ���º������ˣ�����һ���ʻ���", me);
		say("�ҿ�����18֧õ�壬18֧������18֧�ٺϣ���18֧�����ǣ�", me);
		say("�ҿ����������ݿ�������࣬��ͷ����������࣬Ψһ����ģ��������������۾���", me);
		say("��˵�������ɣ�ѩ����", me);
		say("����", me);
		AddMenuItem("��̾�˿���", "$0sigh", me);
		AddMenuItem("����������", "", me);

		me->set_temp("pending/ѩ��", 400);
		SendMenu(me);
		return;
	}

	if(verb == "sigh" && me->query_temp("")
}

NPC_END;
