//xy_baihu2.h �׻�����������
//�ز� 2002��12��12

NPC_BEGIN(CNxy_baihu2);

virtual void create()
{    
	set_name("˫˫", "shuang shuang");
	set("long","�������ಢ����Ϊһ�塣");	
	
    set("title","�׻�����");

    set("str", 22); 
    set("int", 22);
    set("con", 22);
    set("dex", 22);

    set("icon",random(46)+1);

    set("max_hp", 12000);
    set("mp", 6000);
    set("max_mp", 6000);
    set("mp_factor", 70); 
    set("combat_exp", 3000000); 
	
	set("no_kill",1);

    set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

    set_skill("shenzhao_gong", 100);
	set_skill("celestrike", 100);
	set_skill("tiexue_steps", 100);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 120);
    set("apply/damage", 70);

}

NPC_END;




