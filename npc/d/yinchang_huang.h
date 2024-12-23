//yinchang_huang.h

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_huang);

virtual void create()
{
    set_name("���Ϲ�", "huang yaoshi");
    set("title", "�һ�����");
    set("nickname",  "��а"  );
    set("gender", "����");
    set("age", 42);
    set("icon",old_man2);

    set("long", "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
	
    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3500);
    set("max_mp", 3500);
    set("mp_factor", 100);
	
    set("combat_exp", 1500000);
    
	
    set_skill("force", 150);             // �����ڹ�
    set_skill("bibo_shengong", 150);     // �̲���
    set_skill("claw", 150);              // ����צ��
    set_skill("hand", 150);              // �����ַ�
    set_skill("finger", 170);            // ����ָ��
    set_skill("tanzhi_shentong", 170);   // ��ָ��ͨ
    set_skill("unarmed", 180);           // ����ȭ��
    set_skill("strike", 180);            // ����ȭ��
    set_skill("luoying_shenzhang", 180);     // ��Ӣ����
    set_skill("xuanfeng_leg", 180);      // ����ɨҶ��
    set_skill("dodge", 150);             // ��������
    set_skill("anying_fuxiang", 120);    // ��Ӱ����
    set_skill("parry", 150);             // �����м�
    set_skill("sword", 200);             // ��������
    set_skill("luoying_shenjian", 200);  // ��Ӣ��
    set_skill("yuxiao_jianfa", 200);       // ���｣��
    set_skill("lanhua_shou", 200);       // ������Ѩ��
    set_skill("qimen_wuxing",150);       // ��������
    set_skill("count",150);              // ��������
    set_skill("literate",150);           // ����ʶ��
	
    map_skill("force"  , "bibo_shengong");
    map_skill("finger" , "tanzhi_shentong");
    map_skill("hand"   , "lanhua_shou");
    map_skill("unarmed", "luoying_shenzhang");
    map_skill("strike" , "xuanfeng_leg");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("parry"  , "luoying_shenjian");
    map_skill("sword"  , "yuxiao_jianfa");
	
    create_family("�һ���", 1, "����");
	
    carry_object("cloth")->wear();
    carry_object("yuxiao")->wield();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say("  �ߵƴ�ʦ������λһ������ȴ����Ϊɮ���˾����������������������⡣");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="yideng-dashi")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;