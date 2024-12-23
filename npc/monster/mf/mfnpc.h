#define MFNPC_BEGIN(npc_name)	class npc_name : public CNmfnpc	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MFNPC_END		};	

NPC_BEGIN(CNmfnpc);

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	CContainer * baowu,* RMB;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		else break;
	}
	if(me)
		baowu = generate_baowu(me);//�����ʱû����ҵĻ����᲻����������أ��� �ز� 2002��3��28
	CChar * killer = (CChar *)find_object(query_temp("last_damage_from"), 1);

	if(baowu) baowu->move(environment());
	RMB=load_item("coin");
	RMB->set_amount(random(1000)+1);
	if(RMB) RMB->move(environment());

	if(killer)
	{
		reward_exp(killer);	
	}

	message_vision("$N���Ʋ��룬һ�������ذδС�����Ȧ�⣬գ�ۼ����ʧ�������ǰ��", this);
	destruct(this);
}

void reward_exp(CChar * me)
{
	g_Combatd.Killer_Reward(me, this);
}

char * chat_msg()
{
	//����Ƿ�������ˡ�
	if(random(10))
	{
		//��鳡�����Ƿ������
		DTItemList search;

		CopyList(&search, environment()->Get_ItemList());

		POSITION p;
		p = search.GetHeadPosition();
		while(p)
		{
//			char msg[40];
			CContainer * obj = search.GetNext(p);
			if(userp(obj))
			{
/*				if(! random(5) 
					&& query("mfnpc_lvl") > obj->query_temp("apply/protect")
					&& command(snprintf(msg, 40, "kill %ld", obj->object_id())))
*/					return 0;
			}
			else if(obj->Query(CAN_GET) && ! random(3) && !obj->query("lost"))
			{
				message_vision("$N���Ĵ����ˣ�������һ�ף�ʰ����$n�ʹ��������ҡ�", this, obj);
				destruct(obj);
				return 0;
			}
		}
		
		return 0;
	}

	message_vision("$N���ҿ�����Ȼ������һԾ����ʧ�����Ұ�У�", this);
	destruct(this);
	return 0;
}

CContainer * generate_baowu(CChar * me)
{
	CContainer * baowu = NULL;
	int diff=5;		//�͵ȼ�װ���ļ��ʿ��Ʋ�������ֵԽ�󣬳��ֵļ���ҲԽ��Ĭ��Ϊ4
	int diff_high=5;	//�ߵȼ�װ���ļ��ʿ��Ʋ�������ֵԽС�����ֵļ���ҲԽ��Ĭ��Ϊ5
	int level = query("mf/level");	//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
	int odds=query("mf/odds");		//	�������Ｘ��,����Ϊodds/100
	int count=query("mf/count");	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	int boss=query("boss");//����Ƿ���BOSS�� 
	if(random(100)<=odds)
	{
		int mf=random(level)+random(me->query_temp("apply/mf")/20);
		if(mf>level)
			mf=random(level-39)+40;
		if(mf>90 && random(count/100))
			mf=random(46)+40;
		if(mf>me->query("level"))
			mf=random(int(me->query("level")/2))+int(me->query("level")/2);
		switch(mf)
		{
		case 10:
			if(random(diff))
			{
				static char item[20][20] =
				{				
					"yuchi","egg","caomei","baozi","tanghulu","rice3","qingshui_hulu",
					"peanut","jiudai","jitui","gouroutang","fish","zhutou","hulu2",
					"hu","hdjiudai","caidao","duanjian","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(20)]));
			}
			break;
		case 11:
			if(random(diff))
			{
				static char item[19][20] =
				{				
					"flower_leaf","gancheng","kandao","mudao","mugun","mujian","muyu",
					"muyuchui","shikuai","shitou","shuzhi","shuzhi2","tea_leaf","tieqiao",
					"walkingstick","yangbian","yaoqin","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(19)]));
			}
			break;
		case 12:
			if(random(diff))
			{
				static char item[28][20] =
				{				
					"zhitao","zhujian","baichou","baipao","baiyi","bduanqun","beixin","belt",
					"blackcloth","bluecloth","boots","bupao","bu_shoes","cloth","cloth2","connie",
					"cynrobe","doupeng","goupi","greenrobe","green_cloth","greyrobe","guazi",
					"gunny_shoes","heiyi","hongchouxiaoshan","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(28)]));
			}
			break;
		case 13:
			if(random(diff))
			{
				static char item[49][20] =
				{				
					"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
					"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
					"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
					"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
					"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
					"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(49)]));
			}
			break;
		case 14:
			if(random(diff))
			{
				static char item[49][20] =
				{				
					"huwan","huyao","jinduan","kenao","linen","luo_cloth","magcloth","magua","male1_cloth",
					"male2_cloth","male3_cloth","male4_cloth","male6_cloth","male7_cloth","male8_cloth","maotan",
					"mask","qingyi","qing_cloth","shoutao","tduanqun","test","tiehuwan","tiehuyao","tieshou",
					"tiezhitao","tongqun","wcloth","wdahui","weibo","whitecloth","whitecloth1","white_robe",
					"xiaoao","xu_cloth","yaodai","yayi_cloth","ycloth","zhitao","soup2","soup","shrimp","sherou",
					"mian","marz","chicken","bocai_fentiao","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(49)]));
			}
			break;
		case 15:
			if(random(diff))
			{
				static char item[89][20] =
				{				
					"zongzi","backleg","yangrou","turou","tofu","puercha","paomo","mizhitianou","mala_doufu",
						"furong_huagu","baozi2","mixian","huotui","hamigua","luobo","geng","gao4","shedan",
						"zaisheng","suanmei","niupidai","changbian","changjian","changqiang","chanzhang",
						"dadao2","feihuangshi","fenshuici","fork","fuchen","futou","gangdao","gangjian",
						"gangzhang","hammer","jiandao","mutang","senggun","shebian","shield","shortblade",
						"wandao","wodao","xiuhua","yuxiao","zheshan","zhubang","b_jiasha","changpao","choupao",
						"dao_cloth","doupeng2","hat","huangshan","hui_cloth","hupi","jiasha","junfu","piqiu",
						"qingyi2","sengmao","seng_cloth","shepi","shoe","shoes","shuikao","tiebeixin","toukui",
						"wchangqun","xian_cloth","map","yadan","xiaren2","shanhu_baicai","rice","nang","liuli_qiezi",
						"kaoyangtui","kaoya","jiaxin_biji","gourou","birddie","basi_shanyao","yezi","yangjing",
						"xueli","suya","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(89)]));
			}
			break;
		case 16:
			if(random(diff))
			{
				static char item[34][20] =
				{				
					"suji","mangguo","huotui2","gao","gaoyao","gao3","ping","dadao","gangbiao","heilongbian",
					"jiedao","panguanbi","qimeigun","qin","shezhang","shortsword","shutonggun","tielianzi",
					"tiepipa","tie_gan","tongren","tudao","zijinchui","changpao2","cheng_cloth",
					"daopaocyan_cloth","jindai","jjunfu","ni_cloth","ni_xie","pink_cloth","p_jiasha",
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(34)]));
			}
			break;
		case 17:
			if(random(diff))
			{
				static char item[19][20] =
				{				
					"skirt","y_jiasha","zhaohong","yeerba","qiguoji","jiaohuaji","qingke_m","qingcha",
					"cleansword","hugesword","taomujian","tiegun","tiejiang","tieshou","wuqing_sword",
					"c_jiasha","dachang","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(19)]));
			}
			break;
		case 18:
			if(random(diff))
			{
				static char item[43][20] =
				{				
					"diaopi","jin","r_jiasha","shudai","pork","fotiaoqiang","tiebian","male5_cloth","qingpao",
					"qun","tiejia","xuelian2","fengmi","axe","biandan","dafu","dagger","huaji","ruanjian",
					"yaochu","male_shoe","pixue","sengxie","seng_xie","surcoat","ttoujin","zhenzhu","menghan_yao",
					"xionghuang","chaidao","mandao","putongbishou","snowsword","xiao","zhuyebiao","color_dress",
					"dress","fu_cloth","goldring","gui_dress","jade_belt","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(43)]));
			}
			break;
		case 19:
			if(random(diff))
			{
				static char item[13][20] =
				{				
					"lace","liu_dress","mini_dress","moon_dress","necklace","pink_dress","qi_dress",
					"red_dress","scarf","sha_dress","shouzhuo","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(13)]));
			}
			break;
		case 20:
			if(random(diff))
			{
				static char item[17][20] =
				{				
					"xiu_cloth","xiu_scarf","yan_dress","zi_dress","yangxin","mitao","yuchandan",
					"xxqingxin_san","jingxin_san","caoxie","cycle","dao_xie","female1_cloth","female2_cloth",
					"female3_cloth","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(17)]));
			}
			break;
		case 21:
			if(random(diff))
			{
				static char item[20][20] =
				{				
					"female4_cloth","female5_cloth","female6_cloth","female7_cloth","female8_cloth",
					"female_shoe","flower_shoe","marry_1","marry_dress","yupei","yaopin_1","huoqiang",
					"jiujiebian","qingzugang","rose","shedangao","nverhong","honey","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(20)]));
			}
			break;
		case 22:
			if(random(diff))
			{
				static char item[12][20] =
				{				
					"arrow","qingzuzang","tiedan","xem_sword","yuzhu_zhang","baguafu",
					"ring","heiyugao","tianxiang_gao","yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(12)]));
			}
			break;
		case 23:
			if(random(diff))
			{
				static char item[11][20] =
				{				
					"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
					"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(11)]));
			}
			break;
		case 24:
			if(random(diff))
			{
				static char item[11][20] =
				{				
					"zhanyi","bilinzhen","cuiyu","xuelian","jiuping2","jiuping",
					"baihongjian","sword_2","junzijian","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(11)]));
			}
			break;
		case 25:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","yijing3",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 26:
			if(random(diff))
			{
				static char item[2][20] =
				{				
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(2)]));
			}
			break;
		case 27:
			if(random(diff))
			{
				static char item[2][20] =
				{				
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(2)]));
			}
			break;
		case 28:
			if(random(diff))
			{
				static char item[2][20] =
				{				
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(2)]));
			}
			break;
		case 29:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 30:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"youlongsword","yufeng_zhen","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 31:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"hedinghong","shanshen","blade_2","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 32:
			if(random(diff))
			{
				static char item[2][20] =
				{				
					"yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(2)]));
			}
			break;
		case 33:
		case 34:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"shenghuo_ling","jinsijia","yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(5)]));				
			}
			break;
		case 35:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"yaopin_2","yaopin_1",
					"taibaizao",	//̫����
					"zhuguo","yijing3",
				};
				baowu = load_item((item[random(5)]));				
			}
			break;
		case 36:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"xuedao","ring_whip","yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 37:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo","yijing3",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 38:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"leizhendang","sword_3","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 39:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"longquansword","xuantiesword","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 40:
			if(random(diff))
			{
				static char item[9][20] =
				{				
					"fojing100","fojing101","fojing11","fojing20","fojing200","fojing201","fojing21","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(9)]));
			}
			break;
		case 41:
			if(random(diff))
			{
				static char item[9][20] =
				{				
					"liumai_sword","wuji1","wuji2","wuji3","yaopin_2","shouwu","sanxiaosan","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(9)]));
			}
			break;
		case 42:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","yijing3",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 43:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo","yijing3",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 44:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"jinhua","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 45:
			if(random(diff))
			{
				static char item[8][20] =
				{				
					"38huoqiang",		//�����˻�ǹ
					"diaojiandai",		//С�ɰ������
					"lantiandai",		//�������
					"guiling","jinlun","chanhe_book1","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(8)]));
			}
			break;
		case 46:
			if(random(diff))
			{
				static char item[6][20] =
				{				
					"chanhe_book2","chanhe_book3","musicbook1","yaopin_2","yaopin_1",
					"jinhuantoushi",		//��ͷ��
				};
				baowu = load_item((item[random(6)]));
			}
			break;
		case 47:
			if(random(diff))
			{
				static char item[7][20] =
				{				
					"skin","throw_book","putizi","yaopin_2","yaopin_1","zhuguo",
					"linboxie",				//�貨Ь
				};
				baowu = load_item((item[random(7)]));
			}
			break;
		case 48:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo","yijing3",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 49:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"feather","yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 50:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_3","yaopin_2","yaopin_1",
					"btzheng",	//BT�廨��
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 51:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"feicui","yaopin_2","yaopin_1",
					"yunshenglv",	//������
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 52:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"zhemei_book1","yaopin_2","yaopin_1","zhuguo","yijing3",
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 53:
		case 54:
			if(random(diff))
			{
				baowu = load_item("yanshiling");	//������
				baowu->create(1+random(me->query("level")/4+me->query("int")/2));
			}
			break;
		case 55:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
					"xuantiebishou",		//����ذ��
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 56:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
					"qunxing_tu",//Ⱥ����ͼ
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 57:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"shunvjian","yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 58:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"sun_book","yaopin_2","yaopin_1",
					"bolanxie",			//��������Ь
					"qunxing_tu",	//Ⱥ����ͼ
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 59:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
					"qunxing_tu",//Ⱥ����ͼ
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 60:
			if(random(diff))
			{
				static char item[6][20] =
				{				
					"jiuhua","yaopin_2","yaopin_1",
					"haoseshan",		//���Ӻ�ɫ����
					"xiantianyu",		//�������̾���
					"poliquan",			//��������
				};
				baowu = load_item((item[random(6)]));
			}
			break;
		case 61:
			if(random(diff))
			{
				static char item[2][20] =
				{				
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(2)]));
			}
			break;
		case 62:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","yijing3",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 63:
			if(random(diff))
			{
				static char item[4][20] =
				{				
					"kuihua","yaopin_2","yaopin_1","yijing3",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 64:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 65:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"xblade","yaopin_2","yaopin_1","zhuguo",
					"fannaomao",		//����ȫ��ñ
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 66:
			if(random(diff))
			{
				static char item[3][20] =
				{				
					"bojuan",
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 67:
		case 68:
			if(random(diff))
			{
				static char item[2][20] =
				{				
					"yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(2)]));
			}
			break;
		case 69:
			if(random(diff))
			{
				static char item[5][20] =
				{				
					"wuchangdan",		//�޳���
					"shajiezhi",		//ɵ����ָ
					"renshen","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 70:
			if(!random(diff_high) && boss)
			{
				static char item[6][20] =
				{				
					"tiancanbaojia",		//��ϱ���
					"lvzhuxiao",			//������
					"bishou","zhifapu","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(6)]));
			}
			break;
		case 71:
			if(!random(diff_high) && boss)
			{
				static char item[5][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
					"newyear",		//�������
					"newyear1",		//���̴���
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 72:
		case 73:
			if(!random(diff_high))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 74:
			if(!random(diff_high))
			{
				static char item[3][20] =
				{				
					"jinshe_zhui","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 75:
			if(!random(diff_high) && boss)
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1",
					"zidiaopifeng",		//��������
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 76:
			if(!random(diff_high))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo","yijing3",
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 77:
		case 78:
		case 79:
			if(!random(diff_high))
			{
				static char item[4][20] =
				{				
					"liaochengpao",		//��ȴ��Ե��
					"yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(4)]));
			}
			break;		
		case 80:
			if(!random(mf-80+diff_high) )
			{
				static char item[6][20] =
				{				
					"baixiang","yaopin_2","yaopin_1","zhuguo",
					"dagoubang",		//�����򹷰�
					"luoshenjin",		//���񷽽�
				};
				baowu = load_item((item[random(6)]));
			}
			break;
		case 81:
			if(!random(mf-80+diff_high))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 82:
			if(!random(mf-80+diff_high) )
			{
				static char item[5][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
					"yinguozhu",		//�������
					"conglinjian",		//���齣
				};
				baowu = load_item((item[random(5)]));
			}
			break;
		case 83:
			if(!random(mf-80+diff_high))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","zhuguo",
					"dulonglian",		//����������
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 84:
		case 85:
			if(!random(mf-80+diff_high))
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1",
					"fengyizhen",		//���¶���
					"zueiyupao",		//׺����
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 86:
			if(!random(mf-80+diff_high))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1",
					"yanshuhua",		//���״�컨
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 87:
			if(!random(mf-80+diff_high))
			{
				static char item[3][20] =
				{				
					"baojia","yaopin_2","yaopin_1",
				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 88:
			if(random(diff))
			{
				baowu = load_item("yanshiling");	//������
				baowu->create(1+random(me->query("level")/2+me->query("int")/2));
			}
			break;
		case 89:
			if(!random(mf-80+diff_high))
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1",
					"qinjianhun",	//����ʯ*��

				};
				baowu = load_item((item[random(3)]));
			}
			break;
		case 90:
			if(!random(mf-80+diff_high))
			{
				static char item[7][20] =
				{				
					"renshenguo","cwbdao","yaopin_2","yaopin_1",
					"zwsword",			//���佣
					"mingwang_jian",	//������
					"jinlianxie",		//�˴����Ь
				};
				baowu = load_item((item[random(7)]));
			}
			break;
		case 91:
			if(!random(mf-80+diff_high) && boss)
			{
				static char item[4][20] =
				{				
					"yaopin_2","yaopin_1","langyabang",
					"shenshe_staff",		//�϶�������
				};
				baowu = load_item((item[random(4)]));
			}	
			break;	
		case 92:
			if(!random(mf-80+diff_high))
			{
				static char item[5][20] =
				{				
					"yaopin_2","yaopin_1",
					
					"zijianhun",		//����ʯ*��
				};
				baowu = load_item((item[random(5)]));
			}	
			break;
		case 93:
			if(!random(mf-80+diff_high) && boss)
			{
				static char item[3][20] =
				{				
					"yaopin_2","yaopin_1",
					"rumengdai",		//�ɻ����η���
				};
				baowu = load_item((item[random(3)]));
			}	
			break;	
		case 94:
		case 95:
			if(!random(mf-80+diff_high) && boss)
			{
				static char item[4][20] =
				{				
					"labazhou","yaopin_2","yaopin_1",
					"ruanweijia",		//������⬼�
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 96:
			if(!random(mf-80+diff_high) && boss)
			{
				static char item[4][20] =
				{				
					"labazhou","yaopin_2","yaopin_1",
					"zhangmenhuan",		//������ָ��
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 97:
			if(!random(mf-80+diff_high))
			{
				static char item[4][20] =
				{				
					"lengyue_baodao","yaopin_2","yaopin_1",
					"cangzuihu",	//����Ը�Ѿƺ�
				};
				baowu = load_item((item[random(4)]));
			}
			break;
		case 98:
			if(!random(mf-80+diff_high) && boss)
			{
				static char item[8][20] =
				{				
					"fumo_dao","jingang_zhao","yaopin_2","yaopin_1",
					"yinmopao",		//��ħ��
					"huanchunwan",	//������
					"baomingdan",	//������
					"wangqing_shi",	//����ʯ
				};
				baowu = load_item((item[random(8)]));
			}
			break;
		case 99:
			if(!random(mf-80+diff_high) && boss)
			{
				static char item[7][20] =
				{				
					"ytjian",		//���콣
					"tulong_dao",	//������
					"xuanwupao",	//�������
					"hanyuzhi",		//�����ָ
					"kuihuaao",		//����С��
					"yaopin_2","yaopin_1",

				};
				baowu = load_item((item[random(7)]));
			}
			break;
		default:
			baowu = load_item("yaopin_2");
			break;
		}
	}
	else
		baowu=load_item("yaopin_1");
	
	return baowu;
}

NPC_END;




