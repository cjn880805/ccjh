//xy_xuanwu7.h �������߲�����
//�ز� 2002��12��12

NPC_BEGIN(CNxy_xuanwu7);

virtual void create()
{    
	set_name("��������", "xuanwu zhunzhe");
	set("long","һֻ��������ĳ�ɫ���ޣ����к��绽��֮�ܡ�");	
	
	set("title","�������");
	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

	set("icon",officer);

    set("max_hp", 25000);
    set("mp", 12000);
    set("max_mp", 12000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 
	
	set("no_kill",1);

    set_skill("force", 350);
	set_skill("club", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("duanhun_qiang", 350);
	set_skill("huanhua_bu", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "huanhua_bu");
    map_skill("club", "duanhun_qiang");
    map_skill("parry", "duanhun_qiang");
    
    set("apply/armor", 200);
    set("apply/damage",150);

	carry_object("huaji")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC�������߷�ŭ�غ��������˭������񣬾�������ǧ������Σ��������ǰ����������");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_53"))
		{
			me->set("xy/renwu4_53",1);//�����������ߣ�ȡ��������ָ��
			load_item("xuanwu_huan")->move(environment());
			tell_object(me, "\n$HIC���������Ĺ�ʽ֮�£������������������ش������ڲ�֧������һɢ¶����ԭ�Ρ�");
			tell_object(me, "$HICֻ�����ڹ���ĳ��߽������ѣ�����Ϊһ��һ�ߣ�һ�����������߽Բ�����ֻ����һö$HIR��ָ��$HIC��ԭ�ء�\n");
		}
	}
	CNpc::die();
}


NPC_END;




