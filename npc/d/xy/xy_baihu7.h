//xy_baihu7.h �׻����߲�����
//�ز� 2002��12��12

NPC_BEGIN(CNxy_baihu7);

virtual void create()
{    
	set_name("�׻�����", "qinglong zhunzhe");
	set("long","�Ѿ��������ɰ׻�ʥ�ޣ������ޱߡ�");	
	
	set("title","�Ϸ����");
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
	set_skill("unarmed", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("celestrike", 350);
	set_skill("tiexue_steps", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
    map_skill("parry", "celestrike");
    
    set("apply/armor", 200);
    set("apply/damage",150);


}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC�׻����߷�ŭ�غ��������˭������񣬾�������ǧ������Σ��������ǰ����������");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_52"))
		{
			me->set("xy/renwu4_52",1);//���ܰ׻����ߣ�ȡ�ð׻�����ѥ
			load_item("baihu_xue")->move(environment());
			tell_object(me, "\n$HIC���������Ĺ�ʽ֮�£��׻��������������ش������ڲ�֧������һɢ¶����ԭ�Ρ�");
			tell_object(me, "$HIC�׻�����һ�����춯�صľ޺���������ʱ����������ɳ�Ե����޷����ۡ���ɳ���󣬰׻��Ѳ�����ֻ��ԭ������һ˫$HIR�׻�����ѥ$HIC��\n");
		}
	}
	CNpc::die();
}


NPC_END;




