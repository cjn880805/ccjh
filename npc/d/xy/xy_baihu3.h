//xy_baihu3.h �׻�����������
//�ز� 2002��12��12

NPC_BEGIN(CNxy_baihu3);

virtual void create()
{    
	set_name("��״֮ʬ", "zhu zhuangshi");
	set("long","���ݻ�β֮��֡�");	
	
    set("title","�׻�����");
	
    set("str", 24); 
    set("int", 24);
    set("con", 24);
    set("dex", 24);
	
    set("icon",random(46)+1);
	
	set("max_hp", 14000);
    set("mp", 7000);
    set("max_mp", 7000);
    set("mp_factor", 80); 
    set("combat_exp", 4000000); 
	
	set("no_kill",1);

    set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);

    set_skill("shenzhao_gong", 150);
	set_skill("celestrike", 150);
	set_skill("tiexue_steps", 150);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 130);
    set("apply/damage", 80);

}

NPC_END;




