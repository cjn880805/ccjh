//xy_baihu1.h �׻�����������
//�ز� 2002��12��12

NPC_BEGIN(CNxy_baihu1);

virtual void create()
{    
	set_name("��β��", "jiouwei hu");
	set("long","���ž���β�͵������");	
	
    set("title","�׻�����");

    set("str", 20); 
    set("int", 20);
    set("con", 20);
    set("dex", 20);

    set("icon",random(46)+1);

    set("max_hp", 10000);
    set("mp", 5000);
    set("max_mp", 5000);
    set("mp_factor", 60); 
    set("combat_exp", 2000000); 
	
	set("no_kill",1);

    set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

    set_skill("shenzhao_gong", 50);
	set_skill("celestrike", 50);
	set_skill("tiexue_steps", 50);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 100);
    set("apply/damage", 50);

}

NPC_END;




