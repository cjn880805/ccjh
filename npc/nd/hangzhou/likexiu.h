// likexiu.h
//zhangdn 2001-07-19

NPC_BEGIN(CNhangzhou_likexiu);

virtual void create()
{
	set_name("������", "li yixiu");
	set("title", "�����ᶽ");	
	set("gender", "����");
	set("age", 54);
	set("long","������һ��������ɷ⽮������һ���书��Ȼ�������ӡ�");
	set("combat_exp", 150000);
        set("shen_type", -1);
	set("attitude", "heroism");
	set("icon",old_man1);

	set_skill("unarmed", 75);
	set_skill("blade", 75);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	
//	carry_object("gangdao")->wield();
        carry_object("tiejia")->wear();
        
	
	
}
NPC_END;
