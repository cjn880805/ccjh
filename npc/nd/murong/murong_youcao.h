// youcao.c �Ĳ�
//sound 2001-07-16

NPC_BEGIN(CNmurong_youcao);

virtual void create()
{
	set_name("�Ļ�", "you cao");
	set("gender", "Ů��");
	set("age", 20);      
	set("title","Ѿ��");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("per", 30);
	set("icon",young_woman12);
	
	set("combat_exp", 13000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_hp",1000);
	set("hp",1000);
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 50);
	set_skill("parry",40);
	set_skill("yanling_shenfa",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
//	carry_object("skirt1")->wear();
	
	set_inquiry("����", "�Ҿ�����٢��ɽׯ��Ѿ���Ļ���");
	set_inquiry("����", "��������٢��ɽׯ���ѵ���û����˵����");
	set_inquiry("����",  "���ʷ��������辭�����������ʣ�ǧ������������㡣");
	set_inquiry("����",  "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�");
	set_inquiry("����",  "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����");
	set_inquiry("������", "���������Ҽ�С�㡣");
	set_inquiry("����ˮ�", "����ˮ��ǰ������ס�ĵط��������ﲻԶ��");
	set_inquiry("����С��", "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�");
	set_inquiry("��٢��ɽׯ",  "���������٢��ɽׯ�ˡ�");
	
	set("chat_chance",20);       
}

virtual char *chat_msg()
{
	return "�Ĳ��������ﵽ����ǧ����������迴���㣬Ҫ����������ɻ��ʵġ���";
}

NPC_END;