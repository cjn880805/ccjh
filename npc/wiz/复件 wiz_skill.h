NPC_BEGIN(CNwiz_skill);

virtual void create()
{
	set_name("技能检查官","jineng ");

	set("icon", young_man6);
	set("gender", "男性" );
	set("age", 19);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);

	set("no_kill",1);//不被列入万劫谷的任务中

};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(wizardp(me)&& !me->query_temp("skill/kill"))
	{
		me->set_temp("skill/kill",1);
		call_out(do_skill, 1);	
	}
	return 1;
}

static void do_skill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CContainer * env=npc->environment();
	CUser * targetx;
	char msg[255];
	static char skill[35][20]={"kongming_quan","lingxu_bu","wuwen_zhua","shenzhao_gong","jinwu_daofa","duanyun_fu","wudu_zhang","yunlong_zhua","yunlong_xinfa","yunlong_shou","yunlong_shengong","yunlong_shenfa","yunlong_jian","yunlong_bian","lovestrike","loveblade","doggieblade","kill_hammer","xixing_dafa","yihun_dafa","xuedao_xinfa","xiaoyao_jian","wudu_shengong","wudu_bian","hujia_daofa","hanxing_bada","guimei_shenfa","xuanwu_douqi","missblade","lovesteps","doomsword","mtg","doggiesword","taixuan_gong","misssword"};
	static char skill_name[54][20]={"buddhism","begging","literate","unarmed","shenghuo_lingfa","lonely_sword","whip","throw","sword","strike","stick","staff","parry","hand","hammer","finger","dodge","dagger","cuff","blade","club","claw","yijinjing","hamagong","kurong_changong","persuading","linji_zhuang","huntian_qigong","yunv_xinfa","yunv_xinjing","seaforce","zixia_shengong","kuihua_xinfa","bahuang_gong","shenghuo_xinfa","shenghuo_shengong","xuantian_shengong","wuzheng_xinfa","jiuyang_shengong","zuoyou_boji","xiantian_gong","xiantian_qigong","jinyan_gong","shenlong_xinfa","shedao_qigong","bibo_shengong","taiji_shengong","wudu_xinfa","beiming_shengong","huagong_dafa","mizong_xinfa","longxiang","hunyuan_yiqi","huifeng_qijue"};
	static int skill_level[54]={281,602,351,355,401,602,301,320,365,301,301,320,380,300,320,301,415,120,300,300,300,320,351,300,280,300,250,270,280,300,300,250,250,300,280,200,300,150,330,180,280,260,240,220,221,300,320,220,300,300,300,280,300,200};	

	for(int i=env->query("count_start");i<env->query("count_start")+200;i++)
	{
		if(i>=100 && i <=110 || i==203) continue;
		targetx=find_online(snprintf(msg,255,"%d",i));
		if (!targetx)
		{
			targetx = add_user();
			targetx->set("id", snprintf(msg,255,"%d",i));
			targetx->LoadFromServer();
		}
		CMapping * skills =targetx->query_skills();
		CVector v;
		skills->keys(v);
		for(int ii=0; ii<v.count(); ii++)
		{
			for(int j=0;j<35;j++)
			{
				if(EQUALSTR(v[ii],skill[j]))
				{
					tell_room(npc->environment(),snprintf(msg,255,"__$HIR %d 拥有非法技能$HIC %s$HIR __",i,v[ii]));
					npc->set_temp("kill",1);
					targetx->delete_skill(v[ii]);
					break;
				}
			}
			for(int j=0;j<54;j++)
			{
				if(EQUALSTR(v[ii],skill_name[j]) )
				{
					npc->set(snprintf(msg,255,"skill/%s",v[ii]),1);
					if((*skills)[v[ii]]>skill_level[j])
					{
						tell_room(npc->environment(),snprintf(msg,255,"$HIR%d的技能$HIC%s$HIR等级非法,等级是$HIC%d$HIR，现在调整为$HIC%d$HIR。",i,v[ii],(*skills)[v[ii]],skill_level[j]));
						npc->set_temp("kill",1);
						(CChar *)targetx->add("combat_exp",((*skills)[v[ii]]-skill_level[j])*100);
						(CChar *)targetx->set_skill(v[ii],skill_level[j]);
						break;
					}
				}
				
			}
			if(!npc->query(snprintf(msg,255,"skill/%s",v[ii])) && (*skills)[v[ii]]>410)
			{
				tell_room(npc->environment(),snprintf(msg,255,"$HIR%d的技能$HIC%s$HIR等级非法,等级是$HIC%d$HIR，现在调整为$HIC410级$HIR。",i,v[ii],(*skills)[v[ii]]));
				npc->set_temp("kill",1);
				npc->set(snprintf(msg,255,"skill/%s",v[ii]),1);
				(CChar *)targetx->add("combat_exp",((*skills)[v[ii]]-410)*100);
				(CChar *)targetx->set_skill(v[ii],410);
			}
		}
		if(npc->query_temp("kill"))
		{
			message_vision(snprintf(msg,255,"--------%d的技能需要检查-----------\n",i),npc);
			npc->delete_temp("kill");
			npc->del("skill");
		}
		targetx->Save();
		destruct(targetx);
	}
	env->add("count_start",200);
	npc->call_out(do_skill, 1);	
}

NPC_END;




