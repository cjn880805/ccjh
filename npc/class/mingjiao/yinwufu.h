//yinwufu.h
//Lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_yinwufu);

virtual void create()
{
	set_name("���и�", "yin youfu");
	set("long","����һλ���ߣ���һ���ײ����ۡ����ǰ�üӥ��������ʹӡ�һ˫�������������䣬���˵�����");
	
	set("title",  "������΢������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",old_man1);
	
	set("age", 58);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);
	
	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang_quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	prepare_skill("cuff", "jingang_quan");
	
	create_family("����", 4, "��΢������");
	
	carry_object("baipao")->wear();
}

NPC_END;