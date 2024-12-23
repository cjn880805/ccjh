#include "../server/Room.h"
#include "../server/Npc.h"

#define MF_BEGIN(room_name)	class room_name : public CRmf	{	public:	room_name(){};	virtual ~room_name(){};
#define MF_END		};	

ROOM_BEGIN(CRmf);

//当角色进入时执行
//用 set("monster_chance", 60) 设置怪物出现几率。0~100
virtual void init(CChar *me)
{
	int chance = query("monster_chance");
	
	if(! chance) chance = 50;
	if(userp(me) && random(100) < chance)
	{
		remove_call_out(present_mfnpc);
		call_out(present_mfnpc, 1, me->object_id());
	}
}

static void present_mfnpc(CContainer * ob, LONG param1, LONG param2)
{
	char msg[20];
	const char * mon;
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;
	int name=random(15)+1;
	snprintf(msg, 20, "mfnpc_%d", name);
	CNpc * mfnpc = load_npc(msg);
	
	mfnpc->set("mf/odds",ob->query("mf/odds"));		//	掉出宝物几率
	mfnpc->set("mf/count",ob->query("mf/count"));	//	珍稀宝物掉出几率（等级70以上为珍稀宝物）
	mfnpc->set("mf/level",ob->query("mf/level"));	//	掉出宝物等级（30-99为宝物）
	if(ob->query("mf/level")>90 && random(2))	//依据场景难度设置BOSS
		mfnpc->set("boss",1);
	mfnpc->move(ob);
	
	mon = mfnpc->querystr("present_msg");
	if(! mon[0])
		mon = "“嘿嘿，人为财死，鸟为食亡”路旁闪出一个$n，挡在$N面前。";
	
	message_vision(mon, me, mfnpc);
	
	CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
	int lock = obj->query("room_locked");
	obj->set("room_locked", lock | FIGHT_NO_JOIN);
	obj->set_name("寻宝战斗", "fight_room");
	obj->move(ob);
	//copyme	
	int lev=(random(10)+15)/10;
	mfnpc->set("str", me->query("str")+random(3));
	mfnpc->set("int", me->query("int")+random(3));
	mfnpc->set("con", me->query("con")+random(3));
	mfnpc->set("dex", me->query("dex")+random(3));
	
	mfnpc->set("max_hp",me->query("max_hp")*2);
	mfnpc->set("eff_hp",me->query("max_hp")*2);
	mfnpc->set("hp", me->query("max_hp")*2);
	mfnpc->set("max_mp", me->query("max_mp"));
	mfnpc->set("mp",  me->query("max_mp"));
	mfnpc->set("mp_factor", me->query("mp_factor"));
	mfnpc->set("combat_exp", int(me->query("combat_exp")*1.3));
	mfnpc->set("level",me->query("level"));
	
	int i=me->query("level");
	if((me->query("level")<30 && me->query_skill("force", 1) < 110 && me->query_skill("dodge", 1) < 110 && me->query_skill("parry", 1) < 110)|| (me->query("level")>=30 && me->query("level")<60 && me->query_skill("force", 1) < 220 && me->query_skill("dodge", 1) < 220 && me->query_skill("parry", 1) < 220)|| (me->query("level")>=60 && me->query("level")<80 && me->query_skill("force", 1) < 285 && me->query_skill("dodge", 1) < 285 && me->query_skill("parry", 1) < 285) || me->query("level")>=80)
	{
		if(i>110)i=110;
	}
	else
		i=120;
	
	switch(name)
	{
	case 1:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("taiji_shengong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("tiyunzong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("taiji_quan", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("taiji_jian", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("blade", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("taiji_dao", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("taoism", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "taiji_shengong");
		mfnpc->map_skill("dodge", "tiyunzong");
		mfnpc->map_skill("unarmed", "taiji_quan");
		mfnpc->map_skill("parry", "taiji_jian");
		mfnpc->map_skill("sword", "taiji_jian");
		mfnpc->map_skill("blade", "taiji_dao");
		break;
	case 2:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("cuff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("staff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("finger", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("kurong_changong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("tiannan_step", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("jinyu_quan", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("wuluo_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("duanjia_sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sun_finger", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("lm_shangyang", 50+i*(lev+mfnpc->query("boss")));	
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "kurong_changong");
		mfnpc->map_skill("dodge", "tiannan_step");
		mfnpc->map_skill("finger", "sun_finger");
		mfnpc->map_skill("cuff", "jinyu_quan");
		mfnpc->map_skill("strike", "wuluo_zhang");
		mfnpc->map_skill("parry", "sun_finger");
		mfnpc->map_skill("sword", "duanjia_sword");
		mfnpc->map_skill("staff", "duanjia_sword");
		
		mfnpc->prepare_skill("cuff", "jinyu_quan");
		mfnpc->prepare_skill("strike", "wuluo_zhang");
		break;
	case 3:
		mfnpc->set_skill("persuading", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("throwing", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("finger", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("blade", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("mahayana", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("buddhism", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("jinding_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("tiangang_zhi", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("huifeng_jian", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yanxing_dao", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("zhutian_bu", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("linji_zhuang", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force","linji_zhuang");
		mfnpc->map_skill("finger","tiangang_zhi");
		mfnpc->map_skill("dodge","zhutian_bu");
		mfnpc->map_skill("strike","jinding_zhang");
		mfnpc->map_skill("sword","huifeng_jian");
		mfnpc->map_skill("blade","yanxing_dao");
		mfnpc->map_skill("parry","huifeng_jian");
		break;
	case 4:
		mfnpc->set_skill("persuading", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hand",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("staff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hamagong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("chanchu_bufa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("shexing_diaoshou", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("lingshe_zhangfa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xunshou_shu",50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "hamagong");
		mfnpc->map_skill("dodge", "chanchu_bufa");
		mfnpc->map_skill("unarmed", "shexing_diaoshou");
		mfnpc->map_skill("hand", "shexing_diaoshou");
		mfnpc->map_skill("parry", "lingshe_zhangfa");
		mfnpc->map_skill("staff", "lingshe_zhangfa");
		break;
	case 5:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));           
		mfnpc->set_skill("huntian_qigong", 50+i*(lev+mfnpc->query("boss")));    
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));           
		mfnpc->set_skill("xianglong_zhang", 50+i*(lev+mfnpc->query("boss")));   
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));      	     
		mfnpc->set_skill("xiaoyaoyou", 50+i*(lev+mfnpc->query("boss")));      
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));           
		mfnpc->set_skill("staff", 50+i*(lev+mfnpc->query("boss")));            
		mfnpc->set_skill("dagou_bang", 50+i*(lev+mfnpc->query("boss")));        
		mfnpc->set_skill("begging", 50+i*(lev+mfnpc->query("boss")));           
		mfnpc->set_skill("xunshou_shu", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "huntian_qigong");
		mfnpc->map_skill("unarmed", "xianglong_zhang");
		mfnpc->map_skill("dodge", "xiaoyaoyou");
		mfnpc->map_skill("parry", "xianglong_zhang");
		mfnpc->map_skill("staff", "dagou_bang");
		
		mfnpc->prepare_skill("unarmed", "xianglong_zhang");
		break;
	case 6:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yunv_xinfa", 50+i*(lev+mfnpc->query("boss")));	
		mfnpc->set_skill("seaforce", 50+i*(lev+mfnpc->query("boss")));		
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yunv_jian", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("smithsword",50+i*(lev+mfnpc->query("boss")));	
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xianyun_bufa", 50+i*(lev+mfnpc->query("boss")));	
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("meinv_quan", 50+i*(lev+mfnpc->query("boss")));    
		mfnpc->set_skill("anranxiaohun_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("tianluo_diwang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "seaforce");
		mfnpc->map_skill("sword", "smithsword");
		mfnpc->map_skill("dodge", "xianyun_bufa");
		mfnpc->map_skill("parry", "anranxiaohun_zhang");
		mfnpc->map_skill("unarmed", "anranxiaohun_zhang");
		break;
	case 7:
		mfnpc->set_skill("cuff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("zixia_shengong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("poyu_quan", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("huashan_sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hunyuan_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("lonely_sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("huashan_shenfa",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("zhengqijue", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("cuff", "poyu_quan");
		mfnpc->map_skill("force", "zixia_shengong");
		mfnpc->map_skill("dodge", "huashan_shenfa");
		mfnpc->map_skill("parry", "lonely_sword");
		mfnpc->map_skill("sword", "lonely_sword");
		mfnpc->map_skill("strike", "hunyuan_zhang");
		break;
	case 8:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hand",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword",50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->set_skill("zhemei_shou",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("liuyang_zhang",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("tianyu_qijian",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yueying_wubu",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("bahuang_gong", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "bahuang_gong");
		mfnpc->map_skill("strike","liuyang_zhang");
		mfnpc->map_skill("dodge", "yueying_wubu");
		mfnpc->map_skill("unarmed", "liuyang_zhang");
		mfnpc->map_skill("strike","liuyang_zhang");
		mfnpc->map_skill("hand", "zhemei_shou");
		mfnpc->map_skill("parry", "liuyang_zhang");
		mfnpc->map_skill("sword","tianyu_qijian");
		
		mfnpc->prepare_skill("strike","liuyang_zhang");
		mfnpc->prepare_skill("hand","zhemei_shou");
		break;
	case 9:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("jiuyang_shengong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("lingfa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("shenghuo_lingfa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("qiankun_danuoyi", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("shenghuo_xinfa", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("parry", "qiankun_danuoyi");
		mfnpc->map_skill("force", "jiuyang_shengong");
		mfnpc->map_skill("dodge", "qiankun_danuoyi");
		mfnpc->map_skill("lingfa", "shenghuo_lingfa");
		break;
	case 10:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("finger",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("taoism",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xiantian_qigong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xiantian_gong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("quanzhen_jianfa",50+i*(lev+mfnpc->query("boss")));  
		mfnpc->set_skill("quanzhen_jian",50+i*(lev+mfnpc->query("boss")));  
		mfnpc->set_skill("jinyan_gong", 50+i*(lev+mfnpc->query("boss")));   
		mfnpc->set_skill("haotian_zhang", 50+i*(lev+mfnpc->query("boss")));   
		mfnpc->set_skill("sun_finger",50+i*(lev+mfnpc->query("boss"))); 
		
		mfnpc->map_skill("force", "xiantian_qigong");
		mfnpc->map_skill("sword", "quanzhen_jianfa");
		mfnpc->map_skill("dodge", "jinyan_gong");
		mfnpc->map_skill("parry", "quanzhen_jianfa");
		mfnpc->map_skill("strike", "haotian_zhang");
		mfnpc->map_skill("finger","sun_finger");
		
		mfnpc->prepare_skill("finger","sun_finger");
		mfnpc->prepare_skill("strike","haotian_zhang");
		break;
	case 11:
		mfnpc->set_skill("buddhism", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("blade", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("claw", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("club", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("cuff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("finger", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hand", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("staff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("whip", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->set_skill("banruo_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("cibei_dao", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("damo_jian", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("fengyun_shou", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("fumo_jian", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hunyuan_yiqi", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("jingang_quan", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("longzhua_gong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("luohan_quan", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("nianhua_zhi", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("pudu_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("qianye_shou", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sanhua_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("riyue_bian", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("shaolin_shenfa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("weituo_gun", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("wuchang_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xiuluo_dao", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yingzhua_gong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yijinjing", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yizhi_chan", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("zui_gun", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("blade", "cibei_dao");
		mfnpc->map_skill("claw", "longzhua_gong");
		mfnpc->map_skill("club", "wuchang_zhang");
		mfnpc->map_skill("cuff", "luohan_quan");
		mfnpc->map_skill("dodge", "shaolin_shenfa");
		mfnpc->map_skill("finger", "yizhi_chan");
		mfnpc->map_skill("force", "yijinjing");
		mfnpc->map_skill("hand", "fengyun_shou");
		mfnpc->map_skill("parry", "nianhua_zhi");
		mfnpc->map_skill("staff", "weituo_gun");
		mfnpc->map_skill("strike", "banruo_zhang");
		mfnpc->map_skill("sword", "fumo_jian");
		mfnpc->map_skill("whip", "riyue_bian");
		
		mfnpc->prepare_skill("finger", "yizhi_chan");
		mfnpc->prepare_skill("strike", "banruo_zhang");
		break;
	case 12:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("staff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->set_skill("shenlong_xinfa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("yixingbu", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("shenlong_bashi", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("huagu_mianzhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("shedao_qigong", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "shenlong_xinfa");
		mfnpc->map_skill("dodge", "yixingbu");
		mfnpc->map_skill("unarmed", "shenlong_bashi");
		mfnpc->map_skill("strike", "huagu_mianzhang");
		mfnpc->map_skill("parry", "shedao_qigong");
		mfnpc->map_skill("sword", "shedao_qigong");
		
		mfnpc->prepare_skill("strike", "huagu_mianzhang");
		mfnpc->prepare_skill("unarmed", "shenlong_bashi");
		break;
	case 13:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));            
		mfnpc->set_skill("claw", 50+i*(lev+mfnpc->query("boss")));              
		mfnpc->set_skill("hand", 50+i*(lev+mfnpc->query("boss")));            
		mfnpc->set_skill("finger", 50+i*(lev+mfnpc->query("boss")));          
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));         
		mfnpc->set_skill("strike", 50+i*(lev+mfnpc->query("boss")));          
		mfnpc->set_skill("leg",50+i*(lev+mfnpc->query("boss")));	           
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));           
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));            
		mfnpc->set_skill("sword", 50+i*(lev+mfnpc->query("boss")));           
		
		mfnpc->set_skill("anying_fuxiang", 50+i*(lev+mfnpc->query("boss")));    
		mfnpc->set_skill("tanzhi_shentong", 50+i*(lev+mfnpc->query("boss")));   
		mfnpc->set_skill("xuanfeng_leg", 50+i*(lev+mfnpc->query("boss")));      
		mfnpc->set_skill("luoying_shenzhang", 50+i*(lev+mfnpc->query("boss")));     
		mfnpc->set_skill("bibo_shengong", 50+i*(lev+mfnpc->query("boss")));     
		mfnpc->set_skill("luoying_shenjian", 50+i*(lev+mfnpc->query("boss")));  
		mfnpc->set_skill("yuxiao_jianfa", 50+i*(lev+mfnpc->query("boss")));       
		mfnpc->set_skill("lanhua_shou", 50+i*(lev+mfnpc->query("boss")));       
		mfnpc->set_skill("qimen_wuxing",50+i*(lev+mfnpc->query("boss")));       
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));           
		
		mfnpc->map_skill("force"  , "bibo_shengong");
		mfnpc->map_skill("finger" , "tanzhi_shentong");
		mfnpc->map_skill("hand"   , "lanhua_shou");
		mfnpc->map_skill("unarmed", "luoying_shenzhang");
		mfnpc->map_skill("strike", "luoying_shenzhang");
		mfnpc->map_skill("leg", "xuanfeng_leg");
		mfnpc->map_skill("dodge"  , "anying_fuxiang");
		mfnpc->map_skill("parry"  , "tanzhi_shentong");
		mfnpc->map_skill("sword"  , "tanzhi_shentong");
		
		mfnpc->prepare_skill("finger", "tanzhi_shentong");
		mfnpc->prepare_skill("hand", "lanhua_shou");
		break;
	case 14:
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("beiming_shengong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("lingboweibu", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("unarmed", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("liuyang_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("blade", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xiaoyao_dao", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("zhemei_shou", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("hand", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "beiming_shengong");
		mfnpc->map_skill("dodge", "lingboweibu");      
		mfnpc->map_skill("hand", "zhemei_shou");
		mfnpc->map_skill("unarmed", "liuyang_zhang");
		mfnpc->map_skill("parry", "xiaoyao_dao");
		mfnpc->map_skill("blade", "xiaoyao_dao");
		
		mfnpc->prepare_skill("hand","zhemei_shou");
		mfnpc->prepare_skill("unarmed","liuyang_zhang");
		break;
	case 15:
		mfnpc->set_skill("throwing", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("feixing_shu", 50+i*(lev+mfnpc->query("boss")));        
		mfnpc->set_skill("force", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("huagong_dafa", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("dodge", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("zhaixinggong", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("strike",50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("xingxiu_duzhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("parry", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("staff", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("tianshan_zhang", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("literate", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("sanyin_wugongzhao", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("claw", 50+i*(lev+mfnpc->query("boss")));
		mfnpc->set_skill("poison", 50+i*(lev+mfnpc->query("boss")));
		
		mfnpc->map_skill("force", "huagong_dafa");
		mfnpc->map_skill("dodge", "zhaixinggong");
		mfnpc->map_skill("strike", "xingxiu_duzhang");
		mfnpc->map_skill("parry", "feixing_shu");
		mfnpc->map_skill("staff", "tianshan_zhang");
		mfnpc->map_skill("unarmed", "xingxiu_duzhang");
		mfnpc->map_skill("claw", "sanyin_wugongzhao");
		
		mfnpc->prepare_skill("unarmed", "xingxiu_duzhang");
		mfnpc->prepare_skill("claw", "sanyin_wugongzhao");
		break;	
	}
	
	mfnpc->move(obj);
	obj->Join_Team(mfnpc, CFightRoom::FIGHT_TEAM_A);
	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
	obj->Begin_Fight(0);
	
}

ROOM_END;



