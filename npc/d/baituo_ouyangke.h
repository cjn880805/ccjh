//ouyangke.h
//code by zwb
//12-16


NPC_BEGIN(CNBaiTuo_ouyangke);

virtual void create()
{
		set_name("����ׯ��","ouyang ke");

        set("long", "����ҡ���ȣ��������ţ�ȴ��Щ���ˣ�Ŀ��ãȻ�ؿ���������Ů���ǡ�");
        set("title", "����ɽ��ׯ��");
        set("gender", "����");
        set("age", 27);
 	set("icon",young_man1);

        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 50);

        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_hp", 2400);
        set("mp", 800);
        set("max_mp", 800);
        set("mp_factor", 20);
        set("combat_exp", 50000);
        set("score", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
};




NPC_END;
