//ouyangfeng.h
//code by zwb
//12-16


NPC_BEGIN(CNBaiTuo_ouyangfeng);

virtual void create()
{
		set_name("����ׯ��","ou yang feng");

        set("long", "���ǰ���ɽׯ������Ϊ��Ů����ƭ�������÷�����\n");
        set("title", "�϶���");
        set("gender", "����");
        set("age", 53);

        set("attitude", "peaceful");
 	set("icon",old_man1);

        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);

        set("hp", 500);
        set("max_hp", 1500);
        set("mp", 1500);
        set("max_mp", 1500);
        set("mp_factor", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 200);
};




NPC_END;
