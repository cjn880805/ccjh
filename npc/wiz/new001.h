//new001.h
//����ʹ ���ָ���Ա
//Lanwood 2001-05-07

NPC_BEGIN(CNnew001);

void create()
{
	set_name("������", "wudang");
	set("long", "һ��Ů���ӡ�");
	set("icon", young_woman1);
	
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
	
	set("combat_exp", 800000);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 100);
	set_skill("lingxu_bu", 100);
	set_skill("wudu_xinfa", 100);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
	create_family("������", 5, "����");
	
	carry_object("changjian")->wield();	
	set("no_talk",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	
	//1����һ����
	if(! strlen(ask))	
	{
		if(me->query("level") < 2)
		{
			say("��ã�����־Ը�ߣ���ʲô�鷳��ϣ������Ϊ���ṩ������",  me);
			
			AddMenuItem("лл�㣬��ô���Ҹ�������ʼ�ء�", "1", me);
			AddMenuItem("���Ƚ�����β����ɡ�", "2", me);
		}
		else
		{
			say("��λ��ɫ���ˣ���ã���Ը���������ƵĹ�����", me);
			AddMenuItem("Ŷ����û��Ȥ��", "", me);
		}

		SendMenu(me);
		return 1;
	}

	string answer = ask;
			
	//2���¼�ѡ��
	if(answer == "1")	//��������
	{
		say("����һ��������Ϊ���������硣ֻҪ���Ŭ��������һ���Ӯ�������˵����صġ�", me);
		say("�����ﹲ��ʮ�������ɣ������Ը�⣬�ҿ���Ϊ������ÿ�����ɵ��ص㡣", me);
		AddMenuItem("");
	}
	else if(answer == "2")
	{
	
	}
	else 
		return 0;

	SendMenu(me);
	return 1;	
}


NPC_END;
