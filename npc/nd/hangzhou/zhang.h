// zhang.h
//zhangdn 2001-07-18

NPC_BEGIN(CNhangzhou_zhangzz);

virtual void create()
{
	set_name("��̫��","zhang taizhong");
	set("title", "���־�����Ӫ����");
	set("nickname", "�����й�");
	set("gender", "����");
	set("age", 43);
	set("long", "��̫���˳ơ������й١�����Ŀ��࣬��һ�Զ̺��ӡ�����ʢ�ԡ�����һǹ��Ī��һ�š�����ָ���ˡ������Թ�����»��Ͷ��͢�����˰�����������Щ������������ֱ�ϡ�");
	set("combat_exp", 750000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("icon", young_man1);
	set("max_mp", 2000);
	set("mp", 2000);
        set("max_hp", 2000);
        set("hp", 2000);
        set("per", 20);
        set("int", 20);
        set("con", 30);
        set("str", 30);
        set("dex", 30);

	set_skill("unarmed", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("taiji_jian", 100);
	set_skill("taiji_quan", 100);
	set_skill("tiyunzong", 100);
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji_shengong");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");

        create_family("�䵱��", 13, "����");
        
 /*       carry_object("green_sword")->wield();
        carry_object("tiejia")->wear();

	add_money("silver", 30);  */

}
NPC_END;