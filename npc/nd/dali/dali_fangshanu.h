// fangshanu.c
//sound 2001-07-16

NPC_BEGIN(CNdali_fangshanu);

virtual void create()
{
	set_name("��ɴŮ", "fangsha nu");
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "һ������İ��Ĵ帾���������ɣ�ר�÷�ɴ��\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 2000);
	set("shen_type", 1);
        set("per", 18);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
	set("icon",young_woman7);	
        set("attitude", "friendly");

        carry_object("bduanqun")->wear();
}

NPC_END;