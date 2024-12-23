// yinchang_yideng.c

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_yideng);

virtual void create()
{
    set_name("�ߵƴ�ʦ", "yideng dashi");
    set("nickname",  "�ϵ�"  );
    set("gender", "����");
    set("age", 52);
    set("icon",old_man2);

    set("long", "�����Ǻųơ��ϵۡ����ߵƴ�ʦ�������λ��ˣ�����ѷλΪɮ����ʦһ�����ƣ��������");
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
    set_skill("finger", 170);            // ����ָ��
    set_skill("dodge", 150);             // ��������
    set_skill("parry", 150);             // �����м�
    set_skill("liumai_shenjian", 200);   // ������
    set_skill("taixuan_gong", 200);      // ̫����
    set_skill("lingxu_bu", 200);         // ���鲽
    set_skill("literate",150);           // ����ʶ��
	
    map_skill("force"  , "taixuan_gong");
    map_skill("finger" , "liumai_shenjian");
    map_skill("dodge"  , "lingxu_bu");
    map_skill("parry"  , "liumai_shenjian");
	
    prepare_skill("finger", "liumai_shenjian");
	
    create_family("����μ�", 17, "����");
	
    carry_object("cloth")->wear();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	//һ�ƴ�ʦ������Ц�����Ż�ҩʦ���˹��ֵ�����ү�ӹ�����!
	command("nali huang");
	say(" �����ں�����֮���Σ������벻��֮�С�");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="huang-yaoshi")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;