#include "wordle.h"


void	print_best_option(char **array, float **val_arr)
{
	int i;
	float big;
	int index;

	i = 0;
	index = 0;
	big = 0;
	while (i < 2308)
	{
		while (array[i] != NULL && array[i][0] == '\0')
			i++;
		if (array[i] == NULL)
			break ;
		if (val_arr[i][0] > big)
		{
			big = val_arr[i][0];
			index = i;
		}
		i++;
	}
	printf("TRY INPUT: %s\n", array[index]);
}

void	filter_yellow(char **array, char letter, int index, float **val_arr)
{
	// checks if given letter is somewhere in the word
	// if it is there BUT it is in the given index -> it is not the right word -> memset
	// if it is not there -> memset
	// if it is there and it is not in the given index -> we i++;

	for (int i = 0; i < 2308; i++)
	{
		if (array[i][index] == letter)
		{
			memset(array[i], 0, 5);
			val_arr[i][0] = -1;
		}
		else
		{
			int ii = 0;
			while (array[i][ii] != '\0' && array[i][ii] != letter)
				ii++;
			if (ii == 5)
			{
				memset(array[i], 0, 5);
				val_arr[i][0] = -1;
			}
		}
	}
}

int	filter_green(char **array, char letter, int index, float **val_arr)
{
	// checks if given letter is in the right place

	int i;
	int x;

	x = 0;
	for (i = 0; i < 2308; i++)
	{
		if (array[i][index] != letter)
		{
			memset(array[i], 0, 5);
			val_arr[i][0] = -1;
		}
	}
	return (x);
}

void	call_filters(t_wordle *data)
{
	int i = 0;
	while (data->green > 0)
	{
		while (data->green_buf[i] != '\0' && data->green_buf[i] == '.')
			i++;
		filter_green(data->arr, data->green_buf[i], i, data->value_arr);
		i++;
		data->green--;
	}
	i = 0;
	while (data->yellow > 0)
	{
		while (data->yellow_buf[i] != '\0' && data->yellow_buf[i] == '.')
			i++;
		filter_yellow(data->arr, data->yellow_buf[i], i, data->value_arr);
		i++;
		data->yellow--;
	}
	black_filter(data);
	print_best_option(data->arr, data->value_arr);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	give_g_indexes(t_wordle *data)
{
	int ig = 0;

	while (data->green_buf[ig])
	{
		if (ft_isalpha(data->green_buf[ig]))
		{
			++data->green;
			data->total_green[data->num_green++] = data->green_buf[ig];
		}
		++ig;	
	}
	

	//for show
/* 	printf("\n\nGREEN:\n");
	for (int f = 0; f < 5; f++)
		printf("arr_g= %d\n", data->arr_g[f]);
	printf("\namount_of_g_chars= %d\n", data->amount_of_g_chars);
	printf("\nvalue of ga= %c\n", data->ga);
	printf("value of gb= %c\n", data->gb);
	printf("value of gc= %c\n", data->gc);
	printf("value of gd= %c\n", data->gd);
	printf("value of ge= %c\n", data->ge); */

}

void	give_y_indexes(t_wordle *data)
{
	int iy = 0;

	while (data->yellow_buf[iy])
	{
		if (ft_isalpha(data->yellow_buf[iy]))
		{
			++data->yellow;
			data->fornow_yellow[data->num_yellow++] = data->yellow_buf[iy];
		}
		++iy;
	}
}

	//for show
/* 	printf("\n\nYELLOW:\n");
	for (int f = 0; f < 5; f++)
		printf("arr_y= %d\n", data->arr_y[f]);
	printf("\namount_of_y_chars= %d\n", data->amount_of_y_chars);
	printf("\nvalue of ya= %c\n", data->ya);
	printf("value of yb= %c\n", data->yb);
	printf("value of yc= %c\n", data->yc);
	printf("value of yd= %c\n", data->yd);
	printf("value of ye= %c\n", data->ye); */


void	give_b_indexes(t_wordle *data)
{
	int ib = 0;

	while (data->black_buf[ib])
	{
		if (ft_isalpha(data->black_buf[ib]))
		{
			++data->black;
		}
		++ib;
	}

	//for show
/* 	printf("\n\nBLACK:\n");
	for (int f = 0; f < 5; f++)
		printf("arr_b= %d\n", data->arr_b[f]);
	printf("\namount_of_b_chars= %d\n", data->amount_of_b_chars);
	printf("\nvalue of ba= %c\n", data->ba);
	printf("value of bb= %c\n", data->bb);
	printf("value of bc= %c\n", data->bc);
	printf("value of bd= %c\n", data->bd);
	printf("value of be= %c\n", data->be); */

}

char	**word_list(void)
{
	char *array[2309] = {"cigar","rebut","sissy","humph","awake",
	"blush","focal","evade","naval","serve","heath","dwarf","model",
	"karma","stink","grade","quiet","bench","abate","feign","major","death",
	"fresh","crust","stool","colon","abase","marry","react","batty","pride","floss",
	"helix","croak","staff","paper","unfed","whelp","trawl","outdo","adobe","crazy","sower",
	"repay","digit","crate","cluck","spike","mimic","pound","maxim","linen","unmet","flesh",
	"booby","forth","first","stand","belly","ivory","seedy","print","yearn","drain","bribe",
	"stout","panel","crass","flume","offal","agree","error","swirl","argue","bleed","delta","flick",
	"totem","wooer","front","shrub","parry","biome","lapel","start","greet","goner","golem","lusty",
	"loopy","round","audit","lying","gamma","labor","islet","civic","forge","corny","moult","basic",
	"salad","agate","spicy","spray","essay","fjord","spend","kebab","guild","aback","motor","alone",
	"hatch","hyper","thumb","dowry","ought","belch","dutch","pilot","tweed","comet","jaunt","enema",
	"steed","abyss","growl","fling","dozen","boozy","erode","world","gouge","click","briar","great",
	"altar","pulpy","blurt","coast","duchy","groin","fixer","group","rogue","badly","smart","pithy",
	"gaudy","chill","heron","vodka","finer","surer","radio","rouge","perch","retch","wrote","clock",
	"tilde","store","prove","bring","solve","cheat","grime","exult","usher","epoch","triad","break",
	"rhino","viral","conic","masse","sonic","vital","trace","using","peach","champ","baton","brake",
	"pluck","craze","gripe","weary","picky","acute","ferry","aside","tapir","troll","unify","rebus",
	"boost","truss","siege","tiger","banal","slump","crank","gorge","query","drink","favor","abbey",
	"tangy","panic","solar","shire","proxy","point","robot","prick","wince","crimp","knoll","sugar",
	"whack","mount","perky","could","wrung","light","those","moist","shard","pleat","aloft","skill",
	"elder","frame","humor","pause","ulcer","ultra","robin","cynic","aroma","caulk","shake","dodge",
	"swill","tacit","other","thorn","trove","bloke","vivid","spill","chant","choke","rupee","nasty",
	"mourn","ahead","brine","cloth","hoard","sweet","month","lapse","watch","today","focus","smelt",
	"tease","cater","movie","saute","allow","renew","their","slosh","purge","chest","depot","epoxy",
	"nymph","found","shall","harry","stove","lowly","snout","trope","fewer","shawl","natal","comma",
	"foray","scare","stair","black","squad","royal","chunk","mince","shame","cheek","ample","flair","foyer","cargo","oxide","plant","olive","inert","askew","heist","shown","zesty","hasty","trash","fella","larva","forgo","story","hairy","train","homer","badge","midst","canny","fetus","butch","farce","slung","tipsy","metal","yield","delve","being","scour","glass","gamer","scrap","money","hinge","album","vouch","asset","tiara","crept","bayou","atoll","manor","creak","showy","phase","froth","depth","gloom","flood","trait","girth","piety","payer","goose","float","donor","atone","primo","apron","blown","cacao","loser","input","gloat","awful","brink","smite","beady","rusty","retro","droll","gawky","hutch","pinto","gaily","egret","lilac","sever","field","fluff","hydro","flack","agape","voice","stead","stalk","berth","madam","night","bland","liver","wedge","augur","roomy","wacky","flock","angry","bobby","trite","aphid","tryst","midge","power","elope","cinch","motto","stomp","upset","bluff","cramp","quart","coyly","youth","rhyme","buggy","alien","smear","unfit","patty","cling","glean","label","hunky","khaki","poker","gruel","twice","twang","shrug","treat","unlit","waste","merit","woven","octal","needy","clown","widow","irony","ruder","gauze","chief","onset","prize","fungi","charm","gully","inter","whoop","taunt","leery","class","theme","lofty","tibia","booze","alpha","thyme","eclat","doubt","parer","chute","stick","trice","alike","sooth","recap","saint","liege","glory","grate","admit","brisk","soggy","usurp","scald","scorn","leave","twine","sting","bough","marsh","sloth","dandy","vigor","howdy","enjoy","valid","ionic","equal","unset","floor","catch","spade","stein","exist","quirk","denim","grove","spiel","mummy","fault","foggy","flout","carry","sneak","libel","waltz","aptly","piney","inept","aloud","photo","dream","stale","vomit","ombre","fanny","unite","snarl","baker","there","glyph","pooch","hippy","spell","folly","louse","gulch","vault","godly","threw","fleet","grave","inane","shock","crave","spite","valve","skimp","claim","rainy","musty","pique","daddy","quasi","arise","aging","valet","opium","avert","stuck","recut","mulch","genre","plume","rifle","count","incur","total","wrest","mocha","deter","study","lover","safer","rivet","funny","smoke","mound","undue","sedan","pagan","swine","guile","gusty","equip","tough","canoe","chaos","covet","human","udder","lunch","blast","stray","manga","melee","lefty","quick","paste","given","octet","risen","groan","leaky","grind","carve","loose","sadly","spilt","apple","slack","honey","final","sheen","eerie","minty","slick","derby","wharf","spelt","coach","erupt","singe","price","spawn","fairy","jiffy","filmy","stack","chose","sleep","ardor","nanny","niece","woozy","handy","grace","ditto","stank","cream","usual","diode","valor","angle","ninja","muddy","chase","reply","prone","spoil","heart","shade","diner","arson","onion","sleet","dowel","couch","palsy","bowel","smile","evoke","creek","lance","eagle","idiot","siren","built","embed","award","dross","annul","goody","frown","patio","laden","humid","elite","lymph","edify","might","reset","visit","gusto","purse","vapor","crock","write","sunny","loath","chaff","slide","queer","venom","stamp","sorry","still","acorn","aping","pushy","tamer","hater","mania","awoke","brawn","swift","exile","birch","lucky","freer","risky","ghost","plier","lunar","winch","snare","nurse","house","borax","nicer","lurch","exalt","about","savvy","toxin","tunic","pried","inlay","chump","lanky","cress","eater","elude","cycle","kitty","boule","moron","tenet","place","lobby","plush","vigil","index","blink","clung","qualm","croup","clink","juicy","stage","decay","nerve","flier","shaft","crook","clean","china","ridge","vowel","gnome","snuck","icing","spiny","rigor","snail","flown","rabid","prose","thank","poppy","budge","fiber","moldy","dowdy","kneel","track","caddy","quell","dumpy","paler","swore","rebar","scuba","splat","flyer","horny","mason","doing","ozone","amply","molar","ovary","beset","queue","cliff","magic","truce","sport","fritz","edict","twirl","verse","llama","eaten","range","whisk","hovel","rehab","macaw","sigma","spout","verve","sushi","dying","fetid","brain","buddy","thump","scion","candy","chord","basin","march","crowd","arbor","gayly","musky","stain","dally","bless","bravo","stung","title","ruler","kiosk","blond","ennui","layer","fluid","tatty","score","cutie","zebra","barge","matey","bluer","aider","shook","river","privy","betel","frisk","bongo","begun","azure","weave","genie","sound","glove","braid","scope","wryly","rover","assay","ocean","bloom","irate","later","woken","silky","wreck","dwelt","slate","smack","solid","amaze","hazel","wrist","jolly","globe","flint","rouse","civil","vista","relax","cover","alive","beech","jetty","bliss","vocal","often","dolly","eight","joker","since","event","ensue","shunt","diver","poser","worst","sweep","alley","creed","anime","leafy","bosom","dunce","stare","pudgy","waive","choir","stood","spoke","outgo","delay","bilge","ideal","clasp","seize","hotly","laugh","sieve","block","meant","grape","noose","hardy","shied","drawl","daisy","putty","strut","burnt","tulip","crick","idyll","vixen","furor","geeky","cough","naive","shoal","stork","bathe","aunty","check","prime","brass","outer","furry","razor","elect","evict","imply","demur","quota","haven","cavil","swear","crump","dough","gavel","wagon","salon","nudge","harem","pitch","sworn","pupil","excel","stony","cabin","unzip","queen","trout","polyp","earth","storm","until","taper","enter","child","adopt","minor","fatty","husky","brave","filet","slime","glint","tread","steal","regal","guest","every","murky","share","spore","hoist","buxom","inner","otter","dimly","level","sumac","donut","stilt","arena","sheet","scrub","fancy","slimy","pearl","silly","porch","dingo","sepia","amble","shady","bread","friar","reign","dairy","quill","cross","brood","tuber","shear","posit","blank","villa","shank","piggy","freak","which","among","fecal","shell","would","algae","large","rabbi","agony","amuse","bushy","copse","swoon","knife","pouch","ascot","plane","crown","urban","snide","relay","abide","viola","rajah","straw","dilly","crash","amass","third","trick","tutor","woody","blurb","grief","disco","where","sassy","beach","sauna","comic","clued","creep","caste","graze","snuff","frock","gonad","drunk","prong","lurid","steel","halve","buyer","vinyl","utile","smell","adage","worry","tasty","local","trade","finch","ashen","modal","gaunt","clove","enact","adorn","roast","speck","sheik","missy","grunt","snoop","party","touch","mafia","emcee","array","south","vapid","jelly","skulk","angst","tubal","lower","crest","sweat","cyber","adore","tardy","swami","notch","groom","roach","hitch","young","align","ready","frond","strap","puree","realm","venue","swarm","offer","seven","dryer","diary","dryly","drank","acrid","heady","theta","junto","pixie","quoth","bonus","shalt","penne","amend","datum","build","piano","shelf","lodge","suing","rearm","coral","ramen","worth","psalm","infer","overt","mayor","ovoid","glide","usage","poise","randy","chuck","prank","fishy","tooth","ether","drove","idler","swath","stint","while","begat","apply","slang","tarot","radar","credo","aware","canon","shift","timer","bylaw","serum","three","steak","iliac","shirk","blunt","puppy","penal","joist","bunny","shape","beget","wheel","adept","stunt","stole","topaz","chore","fluke","afoot","bloat","bully","dense","caper","sneer","boxer","jumbo","lunge","space","avail","short","slurp","loyal","flirt","pizza","conch","tempo","droop","plate","bible","plunk","afoul","savoy","steep","agile","stake","dwell","knave","beard","arose","motif","smash","broil","glare","shove","baggy","mammy","swamp","along","rugby","wager","quack","squat","snaky","debit","mange","skate","ninth","joust","tramp","spurn","medal","micro","rebel","flank","learn","nadir","maple","comfy","remit","gruff","ester","least","mogul","fetch","cause","oaken","aglow","meaty","gaffe","shyly","racer","prowl","thief","stern","poesy","rocky","tweet","waist","spire","grope","havoc","patsy","truly","forty","deity","uncle","swish","giver","preen","bevel","lemur","draft","slope","annoy","lingo","bleak","ditty","curly","cedar","dirge","grown","horde","drool","shuck","crypt","cumin","stock","gravy","locus","wider","breed","quite","chafe","cache","blimp","deign","fiend","logic","cheap","elide","rigid","false","renal","pence","rowdy","shoot","blaze","envoy","posse","brief","never","abort","mouse","mucky","sulky","fiery","media","trunk","yeast","clear","skunk","scalp","bitty","cider","koala","duvet","segue","creme","super","grill","after","owner","ember","reach","nobly","empty","speed","gipsy","recur","smock","dread","merge","burst","kappa","amity","shaky","hover","carol","snort","synod","faint","haunt","flour","chair","detox","shrew","tense","plied","quark","burly","novel","waxen","stoic","jerky","blitz","beefy","lyric","hussy","towel","quilt","below","bingo","wispy","brash","scone","toast","easel","saucy","value","spice","honor","route","sharp","bawdy","radii","skull","phony","issue","lager","swell","urine","gassy","trial","flora","upper","latch","wight","brick","retry","holly","decal","grass","shack","dogma","mover","defer","sober","optic","crier","vying","nomad","flute","hippo","shark","drier","obese","bugle","tawny","chalk","feast","ruddy","pedal","scarf","cruel","bleat","tidal","slush","semen","windy","dusty","sally","igloo","nerdy","jewel","shone","whale","hymen","abuse","fugue","elbow","crumb","pansy","welsh","syrup","terse","suave","gamut","swung","drake","freed","afire","shirt","grout","oddly","tithe","plaid","dummy","broom","blind","torch","enemy","again","tying","pesky","alter","gazer","noble","ethos","bride","extol","decor","hobby","beast","idiom","utter","these","sixth","alarm","erase","elegy","spunk","piper","scaly","scold","hefty","chick","sooty","canal","whiny","slash","quake","joint","swept","prude","heavy","wield","femme","lasso","maize","shale","screw","spree","smoky","whiff","scent","glade","spent","prism","stoke","riper","orbit","cocoa","guilt","humus","shush","table","smirk","wrong","noisy","alert","shiny","elate","resin","whole","hunch","pixel","polar","hotel","sword","cleat","mango","rumba","puffy","filly","billy","leash","clout","dance","ovate","facet","chili","paint","liner","curio","salty","audio","snake","fable","cloak","navel","spurt","pesto","balmy","flash","unwed","early","churn","weedy","stump","lease","witty","wimpy","spoof","saner","blend","salsa","thick","warty","manic","blare","squib","spoon","probe","crepe","knack","force","debut","order","haste","teeth","agent","widen","icily","slice","ingot","clash","juror","blood","abode","throw","unity","pivot","slept","troop","spare","sewer","parse","morph","cacti","tacky","spool","demon","moody","annex","begin","fuzzy","patch","water","lumpy","admin","omega","limit","tabby","macho","aisle","skiff","basis","plank","verge","botch","crawl","lousy","slain","cubic","raise","wrack","guide","foist","cameo","under","actor","revue","fraud","harpy","scoop","climb","refer","olden","clerk","debar","tally","ethic","cairn","tulle","ghoul","hilly","crude","apart","scale","older","plain","sperm","briny","abbot","rerun","quest","crisp","bound","befit","drawn","suite","itchy","cheer","bagel","guess","broad","axiom","chard","caput","leant","harsh","curse","proud","swing","opine","taste","lupus","gumbo","miner","green","chasm","lipid","topic","armor","brush","crane","mural","abled","habit","bossy","maker","dusky","dizzy","lithe","brook","jazzy","fifty","sense","giant","surly","legal","fatal","flunk","began","prune","small","slant","scoff","torus","ninny","covey","viper","taken","moral","vogue","owing","token","entry","booth","voter","chide","elfin","ebony","neigh","minim","melon","kneed","decoy","voila","ankle","arrow","mushy","tribe","cease","eager","birth","graph","odder","terra","weird","tried","clack","color","rough","weigh","uncut","ladle","strip","craft","minus","dicey","titan","lucid","vicar","dress","ditch","gypsy","pasta","taffy","flame","swoop","aloof","sight","broke","teary","chart","sixty","wordy","sheer","leper","nosey","bulge","savor","clamp","funky","foamy","toxic","brand","plumb","dingy","butte","drill","tripe","bicep","tenor","krill","worse","drama","hyena","think","ratio","cobra","basil","scrum","bused","phone","court","camel","proof","heard","angel","petal","pouty","throb","maybe","fetal","sprig","spine","shout","cadet","macro","dodgy","satyr","rarer","binge","trend","nutty","leapt","amiss","split","myrrh","width","sonar","tower","baron","fever","waver","spark","belie","sloop","expel","smote","baler","above","north","wafer","scant","frill","awash","snack","scowl","frail","drift","limbo","fence","motel","ounce","wreak","revel","talon","prior","knelt","cello","flake","debug","anode","crime","salve","scout","imbue","pinky","stave","vague","chock","fight","video","stone","teach","cleft","frost","prawn","booty","twist","apnea","stiff","plaza","ledge","tweak","board","grant","medic","bacon","cable","brawl","slunk","raspy","forum","drone","women","mucus","boast","toddy","coven","tumor","truer","wrath","stall","steam","axial","purer","daily","trail","niche","mealy","juice","nylon","plump","merry","flail","papal","wheat","berry","cower","erect","brute","leggy","snipe","sinew","skier","penny","jumpy","rally","umbra","scary","modem","gross","avian","greed","satin","tonic","parka","sniff","livid","stark","trump","giddy","reuse","taboo","avoid","quote","devil","liken","gloss","gayer","beret","noise","gland","dealt","sling","rumor","opera","thigh","tonga","flare","wound","white","bulky","etude","horse","circa","paddy","inbox","fizzy","grain","exert","surge","gleam","belle","salvo","crush","fruit","sappy","taker","tract","ovine","spiky","frank","reedy","filth","spasm","heave","mambo","right","clank","trust","lumen","borne","spook","sauce","amber","lathe","carat","corer","dirty","slyly","affix","alloy","taint","sheep","kinky","wooly","mauve","flung","yacht","fried","quail","brunt","grimy","curvy","cagey","rinse","deuce","state","grasp","milky","bison","graft","sandy","baste","flask","hedge","girly","swash","boney","coupe","endow","abhor","welch","blade","tight","geese","miser","mirth","cloud","cabal","leech","close","tenth","pecan","droit","grail","clone","guise","ralph","tango","biddy","smith","mower","payee","serif","drape","fifth","spank","glaze","allot","truck","kayak","virus","testy","tepee","fully","zonal","metro","curry","grand","banjo","axion","bezel","occur","chain","nasal","gooey","filer","brace","allay","pubic","raven","plead","gnash","flaky","munch","dully","eking","thing","slink","hurry","theft","shorn","pygmy","ranch","wring","lemon","shore","mamma","froze","newer","style","moose","antic","drown","vegan","chess","guppy","union","lever","lorry","image","cabby","druid","exact","truth","dopey","spear","cried","chime","crony","stunk","timid","batch","gauge","rotor","crack","curve","latte","witch","bunch","repel","anvil","soapy","meter","broth","madly","dried","scene","known","magma","roost","woman","thong","punch","pasty","downy","knead","whirl","rapid","clang","anger","drive","goofy","email","music","stuff","bleep","rider","mecca","folio","setup","verso","quash","fauna","gummy","happy","newly","fussy","relic","guava","ratty","fudge","femur","chirp","forte","alibi","whine","petty","golly","plait","fleck","felon","gourd","brown","thrum","ficus","stash","decry","wiser","junta","visor","daunt","scree","impel","await","press","whose","turbo","stoop","speak","mangy","eying","inlet","crone","pulse","mossy","staid","hence","pinch","teddy","sully","snore","ripen","snowy","attic","going","leach","mouth","hound","clump","tonal","bigot","peril","piece","blame","haute","spied","undid","intro","basal","shine","gecko","rodeo","guard","steer","loamy","scamp","scram","manly","hello","vaunt","organ","feral","knock","extra","condo","adapt","willy","polka","rayon","skirt","faith","torso","match","mercy","tepid","sleek","riser","twixt","peace","flush","catty","login","eject","roger","rival","untie","refit","aorta","adult","judge","rower","artsy","rural","shave"};
	char **alloc_arr;
	int i;

	alloc_arr = (char **)malloc(sizeof(char *) * (2309));
	if (!alloc_arr)
	{
		write(2, "Malloc fail\n", 12);
		exit (1);
	}
	i = 0;
	while (i < 2308)
	{
		alloc_arr[i] = strdup(array[i]);
		if (!alloc_arr[i])
		{
			write(2, "Malloc fail\n", 12);
			exit (1);
		}
		i++;
	}
	alloc_arr[i] = NULL;
	return (alloc_arr);
}

float	*get_value(char str[5])
{
	int i = 0;
	float *value;

	value = (float *)malloc(sizeof(float) * 1);
	if (!value)
	{
		write(2, "Malloc fail\n", 12);
		exit (1);
	}
	while (i < 5)
	{
		if (str[i] == 'a')
			value[0] += 25;
//			value[0] += 43.31;
		else if (str[i] == 'b')
			value[0] += 10;
//			value[0] += 10.56;
		else if (str[i] == 'c')
			value[0] += 17;
//			value[0] += 23.13;
		else if (str[i] == 'd')
			value[0] += 15;
//			value[0] += 17.25;
		else if (str[i] == 'e')
			value[0] += 26;
//			value[0] += 56.88;
		else if (str[i] == 'f')
			value[0] += 9;
//			value[0] += 9.24;
		else if (str[i] == 'g')
			value[0] += 11;
//			value[0] += 12.59;
		else if (str[i] == 'h')
			value[0] += 12;
//			value[0] += 15.31;
		else if (str[i] == 'i')
			value[0] += 23;
//			value[0] += 38.45;
		else if (str[i] == 'j')
			value[0] += 2;
//			value[0] += 1.00;
		else if (str[i] == 'k')
			value[0] += 6;
//			value[0] += 5.61;
		else if (str[i] == 'l')
			value[0] += 18;
//			value[0] += 27.98;
		else if (str[i] == 'm')
			value[0] += 13;
//			value[0] += 15.36;
		else if (str[i] == 'n')
			value[0] += 20;
//			value[0] += 33.92;
		else if (str[i] == 'o')
			value[0] += 22;
//			value[0] += 36.51;
		else if (str[i] == 'p')
			value[0] += 14;
//			value[0] += 16.14;
		else if (str[i] == 'q')
			value[0] += 1;
//			value[0] += 1.00;
		else if (str[i] == 'r')
			value[0] += 24;
//			value[0] += 38.64;
		else if (str[i] == 's')
			value[0] += 19;
//			value[0] += 29.23;
		else if (str[i] == 't')
			value[0] += 21;
//			value[0] += 35.43;
		else if (str[i] == 'u')
			value[0] += 16;
//			value[0] += 18.51;
		else if (str[i] == 'v')
			value[0] += 5;
//			value[0] += 5.13;
		else if (str[i] == 'w')
			value[0] += 7;
//			value[0] += 6.57;
		else if (str[i] == 'x')
			value[0] += 4;
//			value[0] += 1.48;
		else if (str[i] == 'y')
			value[0] += 8;
//			value[0] += 9.06;
		else if (str[i] == 'z')
			value[0] += 3;
//			value[0] += 1.39;
		i++;
	}
	return (value);
}
	/*
E	11.1607%	56.88	M	3.0129%	15.36
A	8.4966%		43.31	H	3.0034%	15.31
R	7.5809%		38.64	G	2.4705%	12.59
I	7.5448%		38.45	B	2.0720%	10.56
O	7.1635%		36.51	F	1.8121%	9.24
T	6.9509%		35.43	Y	1.7779%	9.06
N	6.6544%		33.92	W	1.2899%	6.57
S	5.7351%		29.23	K	1.1016%	5.61
L	5.4893%		27.98	V	1.0074%	5.13
C	4.5388%		23.13	X	0.2902%	1.48
U	3.6308%		18.51	Z	0.2722%	1.39
D	3.3844%		17.25	J	0.1965%	1.00
P	3.1671%		16.14	Q	0.1962%	(1)*/

void	count_values(int loop, t_wordle *data)
{
	int i = 0;
	int x = 0;
	float big;
	char *ptr;

	data->value_arr = (float **)malloc(sizeof(float *) * 2308);
	if (!data->value_arr)
	{
		write(2, "Malloc fail\n", 12);
		exit (1);
	}
	while (data->arr[x] != NULL)
	{
		data->value_arr[x] = get_value(data->arr[x]);
		if (x == 0)
			big = data->value_arr[x][0];
		else if (x > 0 && data->value_arr[x][0] > big)
		{
			big = data->value_arr[x][0];
			ptr = data->arr[x];
		}
		printf("%f\n", data->value_arr[x][0]);
		x++;
	}
	printf("GIVE AS INPUT: %s\n", ptr);
}

int main(void)
{	
	t_wordle	data;
	int loop = 0;

	memset(&data, 0, sizeof(t_wordle));
	data.arr = word_list();
	count_values(loop, &data);
	while (loop < 5)
	{
		char	*g_question = "any \033[0;32mGREEN\033[0m letters?, usage: <..al.>";  
		printf("%s\n", g_question);
		scanf("%6s", data.green_buf);
		if (strlen(data.green_buf) > 5)
		{
			printf("error: too long input.\n");
			exit(1);
		}
		char *y_question = "any \033[1;33mYELLOW\033[0m letters?, usage: <r....>";
		printf("%s\n", y_question);
		scanf("%6s", data.yellow_buf);
		if (strlen(data.yellow_buf) > 5)
		{
			printf("error: too long input.\n");
			exit(1);
		}	
		char	*b_question = "any \033[0;30mBLACK\033[0m letters?(no need for dots here), usage: <ey>";
		printf("%s\n", b_question);
		scanf("%6s", data.black_buf);
		if (strlen(data.black_buf) > 5)
		{
			printf("error: too long input.\n");
			exit(1);
		}
		//only for show
		/* printf("\n\ngreen_buf=	%s\n", green_buf);
		printf("yellow_buf=	%s\n", yellow_buf);
		printf("black_buf=	%s\n\n\n", black_buf); */
		give_g_indexes(&data);
		give_y_indexes(&data);
		give_b_indexes(&data);
		call_filters(&data);
		++loop;
	}
	return (0);
}