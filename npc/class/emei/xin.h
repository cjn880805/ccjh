//xin.h
//Lanwood 2000-01-05

NPC_BEGIN(CNemei_xin);

virtual void create()
{
	set_name("����ʦ̫",  "ningxin shitai");
	set("long", "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��");
	set("gender", "Ů��");
	set("age", 45);
	set("icon", taoistess);
	
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "bonze");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);
		set("foolid",19);
	set("max_hp", 3000);
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("finger", 80);
	set_skill("parry", 90);
	set_skill("strike", 90);
	set_skill("blade", 80);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("tiangang_zhi", 90);
	set_skill("yanxing_dao", 90);
	set_skill("zhutian_bu", 95);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("blade","yanxing_dao");
	map_skill("parry","yanxing_dao");
	
	create_family("������", 4, "����");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
};

virtual void attempt_apprentice(CChar * me)
{
	say("�����ӷ�ƶ�᲻�յ��ӡ�", me);
    say("���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�", me);
	SendMenu(me);
    return;
}

NPC_END;
